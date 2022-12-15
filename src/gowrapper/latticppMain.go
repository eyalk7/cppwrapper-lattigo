package main

import "C"

import (
	_ "lattigo-cpp/ckks"
	_ "lattigo-cpp/dckks"
	_ "lattigo-cpp/marshal"
	_ "lattigo-cpp/ring"
	_ "lattigo-cpp/utils"
)

// required by cgo
func main() {}
