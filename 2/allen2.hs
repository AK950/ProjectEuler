--Project Euler
--Problem 2

fib = 1:1:(zipWith (+) fib (tail fib))
answer = sum $ filter (even) $ takeWhile (<4000000) fib