//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    final class Node {
        let x: Int, y: Int, value: Int
        var leftNode: Node?
        var rightNode: Node?
        
        init(x: Int, y: Int, value: Int) {
            self.x = x
            self.y = y
            self.value = value
        }
        
        func insert(node: Node) {
            if node.x < self.x {
               if let leftNode = self.leftNode {
                   leftNode.insert(node: node)
               } else {
                   leftNode = node
               }
            } else {
                if let rightNode = rightNode {
                    rightNode.insert(node: node)
                } else {
                    rightNode = node
                }
            }
        }
    }
    
    let nodes = nodeinfo.enumerated().map { index, item in
        return Node(x: item[0], y: item[1], value: index + 1)
    }
    var sortedNode = nodes.sorted {
            if $0.y == $1.y { return $0.x < $1.x }
            return $0.y > $1.y
        }
    
    let firstNode = sortedNode.removeFirst()
    let tree = Node(x: firstNode.x, y: firstNode.y, value: firstNode.value)
    sortedNode.forEach { tree.insert(node: $0) }
    
    var preorder: [Int] = []
    var postorder: [Int] = []
    
    func preOrder(node: Node) {
        preorder.append(node.value)
        if let leftNode = node.leftNode { preOrder(node: leftNode) }
        if let rightNode = node.rightNode { preOrder(node: rightNode) }
    }
    
    func postOrder(node: Node) {
        if let leftNode = node.leftNode { postOrder(node: leftNode) }
        if let rightNode = node.rightNode { postOrder(node: rightNode) }
        postorder.append(node.value)
    }
    
    preOrder(node: tree)
    postOrder(node: tree)
    
    return [preorder, postorder]
}
