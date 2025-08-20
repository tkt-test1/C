/* file_word_count.c
 *
 * 概要:
 *   ファイルから単語数を数えるプログラム
 *
 * 実装機能:
 *   - ファイル読み込み
 *   - 空白・改行で区切られた単語数をカウント
 */

#include <stdio.h>
#include <ctype.h>

int countWords(FILE* fp) {
    int count = 0;
    char c, prev = ' ';
    while ((c = fgetc(fp)) != EOF) {
        if (!isspace(c) && isspace(prev)) {
            count++;
        }
        prev = c;
    }
    return count;
}

int main() {
    FILE* fp = fopen("sample.txt", "r");
    if (!fp) {
        printf("Error: file not found.\n");
        return 1;
    }

    int words = countWords(fp);
    printf("Word count: %d\n", words);

    fclose(fp);
    return 0;
}
