.name "zjmp"
.comment "jump"

debut: ld %1, r2
boucle: add r1, r2, r1
xor r1, %15, r4
zjmp %:end
ld %0 , r4
zjmp %:boucle
end: live %-1
zjmp %:debut
