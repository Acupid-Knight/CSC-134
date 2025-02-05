# M2LAB2 - graphics
# MackA
# 2/5/25
# Goal: Learn some simple graphics tools.

from turtle import Screen, Turtle, done

# Set up the screen and turtle
screen = Screen()
screen.bgcolor("black")

t = Turtle()
# Set color and size
t.pencolor("purple")
t.pensize(3)
t.shape("turtle")

# Move turtle to starting position (center-left)
t.penup()
t.goto(-200, 100)  # Adjust starting position closer to the center-left
t.pendown()

# Draw a square with filling
t.fillcolor("OrangeRed2")
t.begin_fill()
for _ in range(4):  # Loop for square
    t.forward(100)
    t.right(90)
t.end_fill()

# Move to the next position and draw a hexagon with filling
t.penup()
t.forward(150)  # Move the turtle to a new position for the hexagon
t.pendown()
t.fillcolor("DeepSkyBlue3")
t.begin_fill()
for _ in range(6):  # Loop for hexagon
    t.forward(80)
    t.right(60)
t.end_fill()

# Draw my initials (let's draw 'A' and 'M')
t.penup()
t.forward(150)  # Move to a new position for initials
t.pendown()

# Drawing the letter 'M' ( Half drawed M, so the A can fit in a little)
t.pencolor("MediumSpringGreen")
t.forward(55)  # Draw the first diagonal line of 'M'
t.right(135)  # Turn to the middle of 'M'
t.forward(75)  # Draw the middle line
t.left(135)  # Turn for the last diagonal line
t.forward(55)  # Complete the 'M'
t.penup()

# Move to draw 'A'
t.backward(75)  # Move back to the starting point of 'A'
t.pendown()
t.left(60)  # Angle for 'A'
t.forward(50)  # Draw the left side of 'A'
t.right(120)
t.forward(50)  # Draw the right side of 'A'
t.backward(25)  # Move back to the center of 'A'
t.right(120)
t.forward(25)  # Draw the horizontal line in 'A' and complete the 'A'
t.pendown()

# Complete drawing
t.hideturtle()

# Finish the drawing
done()
