import sys
import csv
#open file
reader = csv.reader(open('grades.csv','rb'))
reader.next()
#do mission
a = [0,0,0,0,0,0,0,0,0,0,0]
for row in reader:
  i = int(row[2]) 
  a[i]=a[i] + 1 
print 'done input'
num=0
for j in a:
  print 'score ',num,': ',j
  num = num + 1


