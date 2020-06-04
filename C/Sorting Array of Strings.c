int get_count(const char *str)
{
    int n = 0;
    int count[128] = {0};
    if (NULL == str)
    {
        return -1;
    }
    for (; *str != '\0'; str++)
    {
        if (!count[*str])
        {
            count[*str]++;
            n++;
        }
    }
    return n;
}

int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int res = get_count(a) - get_count(b);
    return res == 0 ? lexicographic_sort(a, b) : res;
}

int sort_by_length(const char *a, const char *b)
{
    int res = strlen(a) - strlen(b);
    return res == 0 ? lexicographic_sort(a, b) : res;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if ((*cmp_func)(*(arr + i), *(arr + j)) > 0)
            {
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}