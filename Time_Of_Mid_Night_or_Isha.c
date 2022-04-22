// A Program to calculate the time for the Midnight or the time for 'Isha Salat on various perspectives in Bengali format hh mm (am / pm).
#include <stdio.h>
#include <string.h>
// function to all things since our desired calculation should be happening twice but the value of the variable is changing.
void safe(int h_magrib, int m_magrib, int h_subh, int m_subh, int arr[1], float arr2[1])
{
    int i;
    float f_m_subh;
    if (m_subh < m_magrib)
    {
        m_subh += 60;
        h_magrib += 1;
        m_subh -= m_magrib;
    }
    else
    {
        m_subh -= m_magrib;
    }
    if (h_subh < h_magrib)
    {
        h_subh += 24;
        h_subh -= h_magrib;
    }
    else
    {
        h_subh -= h_magrib;
    }
    m_subh += (h_subh * 60);
    f_m_subh = m_subh * 1.0 / 2;
    h_subh = f_m_subh / 60;
    f_m_subh -= (h_subh * 60);
    arr[0] = h_subh;
    arr2[0] = f_m_subh;

    return;
}
int main()
{
    int h_magrib, m_magrib, h_subh, m_subh, h_sun, m_sun, arr[1], count1 = 0, count2 = 0, temp;
    float arr2[1], last;
    char in[3];

    printf("Enter the time of MAGRIB PRAYER [hh mm (am/pm)]      : ");
    scanf("%d %d %s", &h_magrib, &m_magrib, in);
    temp = h_magrib;
    if (!strcmp(in, "pm") || !strcmp(in, "PM") || !strcmp(in, "Pm") || !strcmp(in, "pM"))
        h_magrib += 12;
    printf("Enter the time of SUBH [hh mm (am/pm)]               : ");
    scanf("%d %d %s", &h_subh, &m_subh, in);
    if (!strcmp(in, "pm") || !strcmp(in, "PM") || !strcmp(in, "Pm") || !strcmp(in, "pM"))
        h_subh += 12;
    printf("Enter the time of SUN RISE [hh mm (am/pm)]           : ");
    scanf("%d %d %s", &h_sun, &m_sun, in);
    if (!strcmp(in, "pm") || !strcmp(in, "PM") || !strcmp(in, "Pm") || !strcmp(in, "pM"))
        h_sun += 12;
    safe(h_magrib, m_magrib, h_subh, m_subh, arr, arr2);
    if (h_magrib > 12)
    {
        h_magrib -= 12;
        count1 = 1;
    }
    if (h_subh > 12)
    {
        h_subh -= 12;
        count2 = 1;
    }
    last = (float)m_magrib + arr2[0];
    if ((float)m_magrib + arr2[0] >= 60)
    {
        last = (float)m_magrib + arr2[0] - 60;
        h_magrib++;
    }
    if ((h_magrib + arr[0]) > 12)
    {
        h_magrib = h_magrib + arr[0] - 12;
        in[0] = 'a';
        in[1] = 'm';
    }
    else
    {
        h_magrib = h_magrib + arr[0];
        if (h_magrib >= 12)
        {
            in[0] = 'a';
            in[1] = 'm';
        }
        else
        {
            in[0] = 'p';
            in[1] = 'm';
        }
    }
    printf("\nThe Safest time for Midnight or 'Isha is valid until : %d : %.2f %s\n", h_magrib, last, in);
    h_magrib = temp;
    if (count1 == 1)
        h_magrib += 12;
    if (count2 == 1)
        h_subh += 12;
    safe(h_magrib, m_magrib, h_sun, m_sun, arr, arr2);
    if (h_magrib > 12)
        h_magrib -= 12;
    if (h_subh > 12)
        h_subh -= 12;
    last = (float)m_magrib + arr2[0];
    if ((float)m_magrib + arr2[0] >= 60)
    {
        last = (float)m_magrib + arr2[0] - 60;
        h_magrib++;
    }
    if ((h_magrib + arr[0]) > 12)
    {
        h_magrib = h_magrib + arr[0] - 12;
        in[0] = 'a';
        in[1] = 'm';
    }
    else
    {
        h_magrib = h_magrib + arr[0];
        if (h_magrib >= 12)
        {
            in[0] = 'a';
            in[1] = 'm';
        }
        else
        {
            in[0] = 'p';
            in[1] = 'm';
        }
    }
    printf("The Other time for Midnight or 'Isha is valid until  : %d : %.2f %s\n", h_magrib, last, in);
    return 0;
}