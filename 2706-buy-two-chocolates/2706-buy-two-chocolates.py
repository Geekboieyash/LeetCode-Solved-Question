class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        return money if money<(x:=sum(sorted(prices)[:2])) else money-x
