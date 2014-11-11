--Project Euler
--Problem 4

answer = maximum $ [x*y | x<-[999,998..100], y<-[999,998..100], (x*y) == (read $ reverse $ show (x*y) :: Int)]