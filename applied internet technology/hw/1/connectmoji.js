function generateBoard(rows, cols, fill)
{
    if(!fill)
        fill = null;
    return {data: new Array(rows * cols).fill(fill), rows: rows, cols: cols};
}

function rowColToIndex(board, row, col)
{
    return row * board.cols + col;
}

function indexToRowCol(board, i)
{
    row = Math.floor(i / board.cols);
    col = i % board.cols;
    return {row: row, col: col};
}

function setCell(board, row, col, value)
{
    res = [...board];
    res.data = [...board.data];
    res.data[rowColToIndex(board, row, col)] = value;
    return res;
}

board1 = generateBoard(2, 3, 9);
console.log(board1);

board2 = generateBoard(3, 3);
i = rowColToIndex(board2, 1, 1);
j = rowColToIndex(board2, 0, 2);
console.log(`i = ${i}, j = ${j}`);

rowCol1 = indexToRowCol(board2, 4);
rowCol2 = indexToRowCol(board2, 2);
console.log(rowCol1);
console.log(rowCol2);
