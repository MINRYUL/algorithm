import Foundation

func solution(_ n:Int, _ lighthouse:[[Int]]) -> Int {
  var graph = Array(repeating: [Int](), count: n + 1)
  var visitied = Array(repeating: false, count: n + 1)
  var result = 0
  lighthouse.forEach {
    graph[$0[0]].append($0[1])
    graph[$0[1]].append($0[0])
  }

  @discardableResult
  func dfs(node: Int) -> Bool {
    visitied[node] = true
    if graph[node].isEmpty { return true }
    var isTurnOn = false

    for i in graph[node] {
      if visitied[i] { continue }
      if !dfs(node: i) {
        if !isTurnOn { result += 1 }
        isTurnOn = true
      }
    }

    return isTurnOn
  }

  visitied[1] = true
  dfs(node: 1)

  return result
}
