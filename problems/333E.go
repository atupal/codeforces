
package main

import "fmt"

var n int
var x []int
var y []int

func input() {
  fmt.Scanf("%d", &n)
  x = make([]int, n)
  y = make([]int, n)
  for i := 0; i < n; i++ {
    fmt.Scanf("%d %d", &x[i], &y[i])
  }
}

func solve() {

}

func main() {
  input()
  solve()
}
