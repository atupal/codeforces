
package main

import (
  "fmt"
)

var x [8]int
var y [8]int

func input() {
  for i := 0; i < 8; i++ {
    x[i] = -1; y[i] = -1
    fmt.Scanf("%d %d", &x[i], &y[i])
    if x[i] == -1 && y[i] == -1 {
      i --
    }
  }
}

func solve() {
  var x1, x2, x3 int = x[0], x[0], x[0]
  for i := 0; i < 8; i++ {
    if x[i] < x1 {
      x1 = x[i]
    } else if x[i] > x3 {
      x3 = x[i]
    }
  }
  var y1, y2, y3 int = y[0], y[0], y[0]
  for i := 0; i < 8; i++ {
    if y[i] < y1 {
      y1 = y[i]
    } else if y[i] > y3 {
      y3 = y[i]
    }
  }
  for i := 0; i < 8; i ++ {
    if x[i] > x1 && x[i] < x3 {
      x2 = x[i]
    }
    if y[i] > y1 && y[i] < y3 {
      y2 = y[i]
    }
  }

  vis := [3][3]int{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  for i := 0; i < 8; i ++ {
    var a, b int = -1, -1
    if x[i] == x1 {
      a = 0
    } else if x[i] == x2 {
      a = 1
    } else if x[i] == x3 {
      a = 2
    }
    if y[i] == y1 {
      b = 0
    } else if y[i] == y2 {
      b = 1
    } else if y[i] == y3 {
      b = 2
    }
    if a != -1 && b != -1 {vis[a][b] = 1}
  }

  for i := 0; i < 3; i ++ {
    for j := 0; j < 3; j ++ {
      if i == 1 && j== 1 {
        continue
      } else if vis[i][j] == 0 {
        fmt.Println("ugly")
        return
      }
    }
  }

  fmt.Println("respectable")
}

func main() {
  input()
  solve()
}
