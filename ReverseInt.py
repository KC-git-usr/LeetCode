def reverse(x):
	str_x = str(abs(x))
	rev_str_x = str_x[::-1]
	if not int(rev_str_x) in range(-2**31, 2**31):
	    return 0
	elif x>0:
	    return int(rev_str_x)
	else:
	    return int(rev_str_x)*-1

print(reverse(1534236469))