--Project Euler
--Problem 3

smallFac x = head [num | num<-[2..x], x `mod` num == 0]

largestPrime 1 = []
largestPrime x = fac : largestPrime (x `div` fac)
						where fac = smallFac x
						
answer = maximum $ largestPrime 600851475143