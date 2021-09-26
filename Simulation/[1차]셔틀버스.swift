//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    var answer = 0
    var timeArray = [Int]()
    
    for time in timetable {
        let splitTime = time.split(separator: ":")
        timeArray.append(Int(splitTime[0])! * 60 + Int(splitTime[1])!)
    }
    
    timeArray.sort()
    
    var shuttle = [Int]()
    var shuttleTime = 540
    for _ in 0..<n {
        shuttle.append(shuttleTime)
        shuttleTime += t
    }
    var shuttleBoarding = Array(repeating: 0, count: shuttle.count)
    var shuttleBoardingLastTime = Array(repeating: 0, count: shuttle.count)
    
    for index in 0..<shuttle.count {
        var boarding = m
        for time in timeArray {
            if shuttle[index] < time { break }
            else if shuttle[index] >= time && boarding > 0 {
                shuttleBoardingLastTime[index] = time
                timeArray.removeFirst()
                boarding -= 1
                if boarding == 0 {
                    break
                }
            }
        }
        shuttleBoarding[index] = boarding
    }
    
    let lastIndex = shuttle.count - 1
    
    if shuttleBoarding[lastIndex] != 0 {
        answer = shuttle[lastIndex]
    } else {
        answer = shuttleBoardingLastTime[lastIndex] - 1
    }
    
    var hour = "\(answer/60)"
    if hour.count < 2 { hour = "0\(hour)" }
    var minute = "\(answer%60)"
    if minute.count < 2 { minute = "0\(minute)" }
    
    
    return "\(hour):\(minute)"
}

print(solution(1, 1, 5, ["00:01", "00:01", "00:01", "00:01", "00:01"]))
