.name "and"
.comment "ET bit a bit"

# REG REG REG
ld %-5, r1
ld %32, r2
and r1, r2, r1
st r1, -511

# DIR REG REG
ld %32, r2
and %64, r2, r1
st r1, -511
and %-4, r2, r1
st r1, -511

# IND REG REG
ld %32, r2
and 0, r2, r1
st r1, -511
and -2, r2, r1
st r1, -511
and 2, r2, r1
st r1, -511


# DIR DIR REG
and %-32, %32, r1
st r1, -511
and %64, %64, r1
st r1, -511

# DIR IND REG
and %-32, -2, r1
st r1, -511
and %64, 0, r1
st r1, -511
and %64, 2, r1
st r1, -511


# IND IND REG
and -3, 10, r1
st r1, -511
and 0, 0, r1
st r1, -511
and 3, -10, r1
st r1, -511
