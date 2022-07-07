#!/bin/sh
# 0 1 2 3 4
# ' \ " ? !

# 0 1 2 3 4
# m r d o c

# 0 1 2 3 4 5 6 7 8 9 A B C
# g t a i o   l u S n e m f

#       14120222 
#FT_NBR2=rcrdmddd

#       1  03 21  2 01
#FT_NBR1=\\\'?\"\\\"\'\\

# 14120222 + 10321201 = 24441423 (5) = 82671 (13) = Salut (gtaio luSnemf)

FT_NBR1=$(echo "$FT_NBR1" | tr \'\\\\\"\?\! '01234')
FT_NBR2=$(echo "$FT_NBR2" | tr mrdoc '01234')
ADDITION=$(echo "obase=13; ibase=5; $FT_NBR1 + $FT_NBR2" | bc)
echo $ADDITION | tr '0123456789ABC' 'gtaio luSnemf'