package main

import (
	"bufio"
	"fmt"
	"os"
)

const inf = 1e9

var n int

type Matrix struct {
	mat []int
}

func NewMatrix() Matrix {
	m := Matrix{mat: make([]int, n*n)}
	for i := 0; i < n*n; i++ {
		m.mat[i] = inf
	}
	return m
}

func multiply(A, B Matrix) Matrix {
	C := NewMatrix()
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			aik := A.mat[i*n+k]
			if aik == inf {
				continue
			}

			for j := 0; j < n; j++ {
				bkj := B.mat[k*n+j]
				C.mat[i*n+j] = min(C.mat[i*n+j], max(aik, bkj))
			}
		}
	}
	return C
}

func qpow(a Matrix, b int) Matrix {
	res := a
	b--
	for b > 0 {
		if b&1 == 1 {
			res = multiply(res, a)
		}
		b >>= 1
		a = multiply(a, a)
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var m int
	fmt.Fscan(reader, &n, &m)

	A := NewMatrix()

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		u--
		v--
		A.mat[u*n+v] = 0
	}

	var k int
	fmt.Fscan(reader, &k)

	for i := 1; i <= k; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		v--
		u--
		A.mat[u*n+v] = min(A.mat[u*n+v], i)
	}

	var q, w int
	fmt.Fscan(reader, &q, &w)
	res := qpow(A, w)

	for i := 0; i < q; i++ {
		var s, t int
		fmt.Fscan(reader, &s, &t)
		s--
		t--
		ans := res.mat[s*n+t]
		if ans == inf {
			fmt.Fprintln(writer, -1)
		} else {
			fmt.Fprintln(writer, ans)
		}
	}

}
