all: 

clone:
	git clone https://github.com/dtolpin/espl131-handouts
push: 
  
	git add lab$(LAB)
	git commit -a -m "$(LAB)"
	git push origin master
