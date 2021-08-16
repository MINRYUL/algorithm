//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ new_id:String) -> String {
    var result = "", beforeDot = false
    let regex = "[a-z0-9._-]"
    
    
    let lowerStr = new_id.lowercased()
    result = lowerStr.getRegex(regex: regex).filter{
        if $0 == "." {
            if beforeDot {
                return false
            }
            beforeDot = true
            return true
        } else {
            beforeDot = false
        }
        return true
    }.joined()
    
    
    if result.first == "." { result.removeFirst() }
    if result.last == "." { result.removeLast() }
    if result.isEmpty { result.append("a") }
    
    if result.count > 15 {
        let endIdx: String.Index = result.index(result.startIndex, offsetBy: 14)
        result = String(result[...endIdx])
        if result.last == "." { result.removeLast() }
    }
    
    while result.count < 3 {
        result.append(String(result.last!))
    }
    
    return result
}


extension String{
    func getRegex(regex: String) -> [String] {
        do {
            let regex = try NSRegularExpression(pattern: regex)
            let results = regex.matches(in: self, range: NSRange(self.startIndex..., in: self))
            return results.map { String(self[Range($0.range, in: self)!]) }
        } catch let error {
            print("invalid regex: \(error.localizedDescription)")
            return []
        }
    }
}

print(solution("=.="))

//아이디의 길이는 3자 이상 15자 이하여야 합니다.
//아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용할 수 있습니다.
//단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.


//1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
//2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
//3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
//4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
//5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
//6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
