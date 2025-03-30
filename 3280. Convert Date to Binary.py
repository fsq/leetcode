class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return '-'.join(["{0:b}".format(int(x)) for x in date.split('-')])