
package main

import (
  "fmt"
)

var n int

func input() {
  fmt.Scanf("%d", &n)
}

func solve() {
  for i := 1; i <= n; i ++ {
    for x := 0; x < n; x ++ {
      if i + x * (n + 1) > (x + 1) * n {
        fmt.Print(i + (x - 1) * (n + 1) + 1, ` `)
      } else {
        fmt.Print(i + x * (n + 1), ` `)
      }
    }
    fmt.Print("\n")
  }
}

func main() {
  input()
  solve()
}
