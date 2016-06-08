and :
return (nb1 & nb2);
or :
return (nb1 | nb2);
xor :
return (nb1 ^ nb2);

------------------------------

add :
return (r3 = r1 + r2);
sub :
return (r3 = r1 - r2);

-------------------------------

aff : (nb)
return (write(1, nb % 256, 1)); // 1 char ascii

ld : load
return (param2 = param1 % IDX_MOD);

lld : long load
return (param2 = param1)

ldi
lldi

st
sti

fork
lfork

zjmp
