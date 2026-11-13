# CS1566 - Lab 4
### Author: Dante Samarco
### University of Pittsburgh
### Fall Semester 2025
### CS1566 - Thumrongsak Kosiyatrakul
---
## Overview
Lab 4 for CS1566 was to generate a triangle and use a transformation matrix to generate more triangles that are bigger & smaller than the initial triangle. 

## Tech Stack
- Programming: C, OpenGL
- Text Editor: VSCode

## Takeaways
Not a terrible amount to say about this lab, truthfully it was just more of the last lab except I had to consider the order in which the triangles generate, so they were drawn to the screen correctly (smaller ones needed to be in front, larger ones needed to be in the back). It's a little weird getting used to drawing things in the back first, then things in the front last, but it's not a difficult mindset to get into. My one real struggle with this was true randomization in C. In C, you unfortunately don't get the same luxury with the standard library's _rand()_ function like you do in something like Java (if I'm remembering right, it's been a while since I've worked with Java code). Nonetheless, it was a fun challenge to overcome. A few looks through old posts on Stack Overflow quickly gave me the reference I was looking for. 

## Result
<img width="562" height="599" alt="Screenshot_From_2026-11-12_08-13-07" src="https://github.com/user-attachments/assets/ed31074a-1070-4243-88c0-9c818dd85304" />
