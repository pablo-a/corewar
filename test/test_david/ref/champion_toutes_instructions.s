.name "Champion toutes les instructions"
.comment "Ce champion permet de verifier que l'on de differences sur aucune instruction"

label:
label_hjgjhgghjhgkjhghkjghjkgkjhgjhgjhgkhjghjghjghjgkhjghjkghjgjhghjghjghjgjhgghgkhjgygkhjgkjhgjhgkygyghjgjhgkhjghjghjgkhjghjgj:

live %1
live %:label
live %-45
live %-0
live %0
live %2000000
live %20000000000000

ld %1, r1
ld %:label, r1
ld 214748364700000000000000000, r1
ld :label, r16

st r1, :label_hjgjhgghjhgkjhghkjghjkgkjhgjhgjhgkhjghjghjghjgkhjghjkghjgjhghjghjghjgjhgghgkhjgygkhjgkjhgjhgkygyghjgjhgkhjghjghjgkhjghjgj
st r1, 42
st r1, r12

add r1, r2, r3

sub r1, r2, r3

and r1, r2, r3
and r1, :label, r3
and r1, 42, r3
and :label, r2, r3
and 12, r2, r3
and :label, :label, r3
and 12, :label, r3
and :label, 42, r3
and 12, 42, r3
and %42, r2, r3
and %:label, r2, r3
and %42, :label, r3
and %:label, :label, r3
and %42, 42, r3
and %:label, 42, r3

or r1, r2, r3
or r1, :label, r3
or r1, 42, r3
or :label, r2, r3
or 1, r2, r3
or :label, :label, r3
or 1, :label, r3
or :label, 42, r3
or 1, 42, r3
or %42, r2, r3
or %:label, r2, r3
or %42, :label, r3
or %:label, :label, r3
or %42, 42, r3
or %:label, 42, r3

xor r1, r2, r3
xor r1, :label, r3
xor r1, 42, r3
xor :label, r2, r3
xor 21, r2, r3
xor :label, :label, r3
xor 21, :label, r3
xor :label, 42, r3
xor 21, 42, r3
xor 42, r2, r3
xor 42, :label, r3
xor 42, 42, r3

zjmp %12
zjmp %:label

ldi r1, %1, r1
ldi r1, %:label, r1
ldi r1, r11, r1
ldi %1, %1, r1
ldi %1, %:label, r1
ldi %1, r11, r1
ldi %:label, %1, r1
ldi %:label, %:label, r1
ldi %:label, r11, r1
ldi 1, %1, r1
ldi 1, %:label, r1
ldi 1, r11, r1
ldi :label, %1, r1
ldi :label, %:label, r1
ldi :label, r11, r1

sti r4, r2, %:label
sti r4, r2, %2
sti r4, r2, r3
sti r4, %:label, %:label
sti r4, %:label, %2
sti r4, %:label, r3
sti r4, %25, %:label
sti r4, %25, %2
sti r4, %25, r3
sti r4, :label, %:label
sti r4, :label, %2
sti r4, :label, r3
sti r4, 25, %:label
sti r4, 25, %2
sti r4, 25, r3

fork %:label
fork %25

lld 25, r5
lld :label, r5
lld %25, r5
lld %:label, r5

lldi r1, %25, r6 
lldi r1, %:label, r6 
lldi r1, r7, r6 
lldi %56, %25, r6 
lldi %67, %:label, r6 
lldi %64, r7, r6 
lldi %:label, %25, r6 
lldi %:label, %:label, r6 
lldi %:label, r7, r6 
lldi 56, %25, r6 
lldi 67, %:label, r6 
lldi 64, r7, r6 
lldi :label, %25, r6 
lldi :label, %:label, r6 
lldi :label, r7, r6 

lfork %965536
lfork %:label

aff r5
