//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {
    func timeConverter(time: String) -> Int {
        return time.split(separator: ":").enumerated().map { index, item in
            switch index {
            case 0: return Int(item)! * 60 * 60
            case 1: return Int(item)! * 60
            case 2: return Int(item)!
            default: return nil
            }
        }.compactMap { $0 }.reduce(0) { $0 + $1 }
    }
    
    func answerConverter(time: Int) -> String {
        var result = ""
        let h = String(time/3600)
        result.append(h.count == 1 ? "0\(h)" : h)
        result.append(":")
        let m = String((time - (Int(h)! * 3600))/60)
        result.append(m.count == 1 ? "0\(m)" : m)
        result.append(":")
        let s = String(time - (Int(h)! * 3600) - (Int(m)! * 60))
        result.append(s.count == 1 ? "0\(s)" : s)
        return result
    }

    let playTime = timeConverter(time: play_time)
    let advTime = timeConverter(time: adv_time)
    
    var prefixSum = Array(repeating: 0, count: playTime + 2)
    
    if playTime == advTime { return "00:00:00" }
    
    logs.forEach { item in
        let time = item.components(separatedBy: "-")
        let startTime = timeConverter(time: time[0])
        let endTime = timeConverter(time: time[1])
        
        prefixSum[startTime] += 1
        prefixSum[endTime] -= 1
    }
    
    for i in 0...playTime { prefixSum[i + 1] += prefixSum[i] }
    
    var maxValue = 0
    var value = 0
    var time = 0
    var lPoint = 0
    let rPoint = advTime
    
    for i in lPoint..<rPoint { maxValue += prefixSum[i] }
    
    value = maxValue
    for i in rPoint...playTime {
        value += prefixSum[i]
        value -= prefixSum[lPoint]
        lPoint += 1
        if value > maxValue {
            maxValue = value
            time = lPoint
        }
    }
    
    return answerConverter(time: time)
}

print(solution("02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:25:50-00:48:29", "00:40:31-01:00:00", "01:37:44-02:02:30", "01:30:59-01:53:29"]))
