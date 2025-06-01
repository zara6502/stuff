    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937_64 rng(seed);
    std::uniform_int_distribution<uint32_t> dist(0, (1LL << 32) - 1);
    
    int scale = 1;
    int size = 10000 * scale;
    uint8_t** square = (uint8_t**)malloc(size * sizeof(uint8_t*));
    for (int i = 0; i < size; i++) {
        square[i] = (uint8_t*)malloc(size * sizeof(uint8_t));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            square[i][j] = 0;
        }
    }

    int onesCount = (int)(size * size * 0.7);
    for (int i = 0; i < onesCount; i++) {
        int row, col;
        do {
            row = dist(rng) % size;
            col = dist(rng) % size;
        } while (square[row][col] == 1);
        square[row][col] = 1;
    }

    int squaresCount = (int)(size * 0.1);
    int minSize = 2;
    int maxSize = 50;
    for (int i = 0; i < squaresCount; i++) {
        int squareSize = minSize + dist(rng) % (maxSize - minSize + 1);
        int startRow = dist(rng) % (size - squareSize + 1);
        int startCol = dist(rng) % (size - squareSize + 1);
        
        for (int r = startRow; r < startRow + squareSize; r++) {
            for (int c = startCol; c < startCol + squareSize; c++) {
                square[r][c] = 1;
            }
        }
    }

    int bigSquareSize = dist(rng) % 100 + 1;
    int bigStartRow = dist(rng) % (size - bigSquareSize + 1);
    int bigStartCol = dist(rng) % (size - bigSquareSize + 1);
    for (int r = bigStartRow; r < bigStartRow + bigSquareSize; r++) {
        for (int c = bigStartCol; c < bigStartCol + bigSquareSize; c++) {
            square[r][c] = 1;
        }
    }
