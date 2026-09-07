class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def sort(points, n):
    for i in range(1, n):
        for j in range(n - i):
            if points[j].x**2 + points[j].y**2 > points[j + 1].x**2 + points[j + 1].y**2:
                points[j], points[j + 1] = points[j + 1], points[j]

n = int(input())
points = []
for i in range(n):
    x, y = map(int, input().split())
    p = Point(x, y)
    points.append(p)

sort(points, n)
for p in points:
    print(f"{p.x} {p.y}")