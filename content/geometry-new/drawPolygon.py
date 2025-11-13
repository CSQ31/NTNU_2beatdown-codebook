/**
 * Author: Ding Fan & ChatGPT
 * Date: 2025-10-11
 * Source:
 * Description: draw single polygon 
 */

n=int(input())
p=[tuple(map(float,input().split()))for _ in range(n)]
p.append(p[0])
x,y=zip(*p)
a,b,c,d=min(x),max(x),min(y),max(y)
s=min(720/(b-a),720/(d-c))
f=open("polygon.svg","w")
f.write("<svg xmlns='http://www.w3.org/2000/svg' width='800' height='800' style='background:white'>\n")
co = lambda pt: (40 + (pt[0] - a) * s, 800 - (40 + (pt[1] - c) * s))
for i in range(n):
    x1, y1 = co(p[i])
    x2, y2 = co(p[i+1])
    f.write(f"<line x1='{x1}' y1='{y1}' x2='{x2}' y2='{y2}' stroke='blue'/>\n")
    f.write(f"<text x='{x1}' y='{y1}' font-size='12'>{p[i][0]},{p[i][1]}</text>\n")
f.write("</svg>")


