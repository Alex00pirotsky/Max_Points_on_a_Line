typedef struct 
{
    int x;
    int y;
}Point;

void quicksort98(long double* a, int left, int right) {
    int i, j;
    long double t, temp;
    if(left > right)
        return;
    temp = a[left];
    i = left;
    j = right;
    while(i != j) {
        while(a[j] >= temp && i < j)
            j--;
        while(a[i] <= temp && i < j)
            i++;
        if(i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = temp;
    quicksort98(a,left, i-1);
    quicksort98(a,i+1, right);
}

int maxPoints(int **points, int pointsSize, int *m)
{
    Point pi;
    Point pj;
    if (pointsSize == 0 || pointsSize == 1) {
        return pointsSize;
    }

    long double* averageOfLevels = (long double*)malloc(sizeof(long double) * (pointsSize * (pointsSize -1) / 2));


    int max = 0;

    for (int i = 0; i< pointsSize; i++)
    {

         pi.x =  points[i][1];
         pi.y =  points[i][0];
        int smaple = 0;
        int index = 0;

        for (int j = 0; j< pointsSize; j++) {
            if (i==j) {
                continue;
            }

         pj.x =  points[j][1];
         pj.y =  points[j][0];

            long double x = pi.x - pj.x;
            long double y = pi.y - pj.y;

            if (x ==0) {
                if (y==0) {
                    smaple++;
                }
                else{
                    averageOfLevels[index++] =INT_MAX;
                }
            }
            else{
                averageOfLevels[index] = ((long double)y)/x;
                index++;
            }
        }

        quicksort98(averageOfLevels, 0, index-1);


        int temp = 1;
        int maxtemp = 0;
        long double pd ;
        long double ld =  INT_MIN;

        for (int i = 0; i < index-1; i++) {
            pd = averageOfLevels[i];
            ld = averageOfLevels[i +1];
            if (pd == ld) {
                temp++;
            }else{
                if (temp > maxtemp) {
                    maxtemp = temp;
                }
                temp=1;
            }
        }


        if (temp > maxtemp) {
            maxtemp = temp;
        }

        if (index >0) {
            maxtemp++;
        }

        maxtemp = maxtemp+ smaple;

        if ( maxtemp > max) {
            max = maxtemp;
        }

        free(averageOfLevels);
        averageOfLevels = (long double*)malloc(sizeof(long double) * (pointsSize * (pointsSize -1) / 2));
    }
    free(averageOfLevels);
    return max;
}
