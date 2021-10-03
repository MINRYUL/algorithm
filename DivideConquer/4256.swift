//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func dfs(inorder: inout [Int], preorder: inout [Int], i: Int, l: Int, r: Int) {
    if l > r || i >= inorder.count { return }
    if l == r {
        print(preorder[i], terminator: " ")
        return
    }
    for j in l...r {
        if preorder[i] == inorder[j] {
            dfs(inorder: &inorder, preorder: &preorder, i: i + 1, l: l, r: j - 1)
            dfs(inorder: &inorder, preorder: &preorder, i: i + j - l + 1, l: j + 1, r: r)
            print(preorder[i], terminator: " ")
            return
        }
    }
}

func main() {
    let t = Int(readLine()!)!

    for _ in 0..<t {
        let n = Int(readLine()!)!

        var preorder = Array(readLine()!.split(separator: " ").map{ Int($0)! })
        var inorder = Array(readLine()!.split(separator: " ").map{ Int($0)! })

        dfs(inorder: &inorder, preorder: &preorder, i: 0, l: 0, r: n)
        print("")
    }

}

main()
