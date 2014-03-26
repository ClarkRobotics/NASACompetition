import Tkinter as tk
global b
global x
b=0
def up():
    global b
    b+=1
    print b
def down():
    global b
    b-=1
    print b
def keypress(event):
    b=0
    
    a=event.keysym;
    if a=='Escape':
        root.destroy()
    if a=='Up':
        up();
    if a=='Down':
        down();
    if a=='Right':
        print "right!"
    if a=='Left':
        print "left!"
    global x
    x = event.char
    if x == "x":
        exit(1)
def always(event):
    global b
    b*=2;
    """elif x == "a":
        print "blaha blaha blaha"
    elif x == "s":
        print "blash blash blash"
    elif x == "d":
        print "blad blad blad"
    else:
        print x"""

root = tk.Tk()
print "Press a key (Escape key to exit):"
root.bind_all('<Key>', keypress,always)

#root.bind_all('<Key>', always)
#while 1:
 #   b+=1;
    
# don't show the tk window
root.withdraw()
root.mainloop()
