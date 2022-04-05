func myAtoi(str string) int {
	res, sign, len, idx := 0, 1, len(str), 0

	for idx < len && (str[idx] == ' ' || str[idx] == '\t') {
		idx++
	}

	if idx < len {
		if str[idx] == '+' {
			sign = 1
			idx++
		} else if str[idx] == '-' {
			sign = -1
			idx++
		}
	}

	for idx < len && str[idx] >= '0' && str[idx] <= '9' {
		res = res*10 + int(str[idx]) - '0'
		if sign*res > math.MaxInt32 {
			return math.MaxInt32
		} else if sign*res < math.MinInt32 {
			return math.MinInt32
		}
		idx++
	}

	return res * sign
}