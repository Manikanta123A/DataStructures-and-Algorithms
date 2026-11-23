
class ProductOfNumbers:

    def __init__(self):
        self.stream = [1]

    def add(self, num: int) -> None:

        if num == 0:
            self.stream = [1]
        else:
            self.stream.append(self.stream[-1] * num)

    def getProduct(self, k: int) -> int:

        if k >= len(self.stream):
            return 0

        return self.stream[-1] // self.stream[-k-1]
