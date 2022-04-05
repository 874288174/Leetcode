func isValidSudoku(board [][]byte) bool {
	var row, col, block [10][10]bool
	for i := range board {
		for j, c := range board[i] {
			if c == '.' {
				continue
			}

			if col[j][c-'0'] || row[i][c-'0'] || block[i/3+j/3*3][c-'0'] {
				return false
			}
			col[j][c-'0'] = true
			row[i][c-'0'] = true
			block[i/3+j/3*3][c-'0'] = true
		}
	}
	return true
}