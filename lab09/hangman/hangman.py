#python hangman
import sys
import random
file =  open('long-words.txt','r')
text = file.read().splitlines()
line = random.choice(text)
llen = len(line)
mstk = 7
win = 0
a=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

print "welcome to python Hangman!"
print line

while mstk > 0 and win < llen:
  print ''
  print "tries left: ", mstk
  flag = 0
  let = raw_input("enter a letter: ")  #exept letter from the user
  i=0
  while i<llen:#print whats known
    
    if let == line[i]:
      a[i] = let
      win+=1
      flag = 1
      print let,
      
    elif a[i] != 0:
      print a[i],
    else:
      print "-",
    i += 1
  if flag == 0:
   mstk+= -1#mistakes 
if mstk > 0:
  print ''
  print "you won!"
else:
  print ''
  print "you are bad"

  
