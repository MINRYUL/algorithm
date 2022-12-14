import Foundation

func solution(_ info:[Int], _ edges:[[Int]]) -> Int {
  var tree = Array(repeating: [Int](), count: info.count)
  var visited = Array(repeating: false, count: info.count)
  edges.forEach { tree[$0[0]].append($0[1]) }
  var result = 0

  func bfs(list: [Int], sheep: Int, wolf: Int) {
    if (list.isEmpty || sheep <= wolf) && sheep != 0 { return }

    for q in list {
      if visited[q] { continue }
      let isWolf = info[q]
      let edges = tree[q]
      visited[q] = true

      switch isWolf {
        case 1: bfs(list: [list, edges].flatMap { $0 }, sheep: sheep, wolf: wolf + 1)
        case 0: bfs(list: [list, edges].flatMap { $0 }, sheep: sheep + 1, wolf: wolf)
        default: continue
      }

      visited[q] = false
    }
    result = result < sheep ? sheep : result
  }

  bfs(list: [0], sheep: 0, wolf: 0)

  return result
}
