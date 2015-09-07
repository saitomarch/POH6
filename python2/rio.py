class Coffee:
    def __init__(self):
        self.water = 0.0
        self.powder = 0.0

    def addWater(self, quantity):
        self.water += quantity

    def addPowder(self, quantity):
        self.powder += quantity

    def getTotal(self):
        return self.powder + self.water

    def taste(self, quantity):
        total = self.getTotal()
        self.water -= quantity * self.water / total
        self.powder -= quantity * self.powder / total

    def getConsentration(self, asPercent):
        return (self.powder / self.getTotal()) * (100.0 if asPercent else 1.0)

coffee = Coffee()

for idx in range(0, int(raw_input().strip())):
    arr = raw_input().strip().split(" ")
    actType = int(arr[0])
    quantity = float(arr[1])
    if actType == 1:
        coffee.addWater(quantity)
    elif actType == 2:
        coffee.addPowder(quantity)
    elif actType == 3:
        coffee.taste(quantity)

print(int(coffee.getConsentration(True)))
