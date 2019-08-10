class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        def f(x : int) -> str:
            if x%3==0 and x%5==0:
                return "FizzBuzz"
            elif x%3 == 0:
                return "Fizz"
            elif x%5 == 0:
                return "Buzz"
            else:
                return str(x)
                
        return [ f(i) for i in range(1, n+1)]