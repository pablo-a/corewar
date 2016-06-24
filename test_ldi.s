.name "ldi"
.comment "ldi"

# REG REG REG
ldi r1, r2, r3
st r3, -511
ld %64, r1
ld %-62, r2
ldi r1, r2, r3
st r3, -511

# DIR REG REG
ldi %-3, r2, r3
st r3, -511
ldi %20, r2, r3
st r3, -511
ldi %-20, r2, r3
st r3, -511

# IND REG REG
ldi -2, r1, r3
st r3, -511
ldi 2, r1, r3
st r3, -511

# DIR DIR REG
ldi %50, %12, r3
st r3, -511
ldi %-20, %30, r3
st r3, -511
ldi %-30, %-30, r3
st r3, -511

# IND DIR REG
ldi -3, %13, r3
st r3, -511
ldi 5, %-6, r3
st r3, -511
