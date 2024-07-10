#include <stdio.h>
#define MaxLength 200
typedef int ElementType;
typedef struct
{
  ElementType Elements[MaxLength];
  int Front, Rear;
  int Time;
} Queue;

void makenullQueue(Queue *pQ)
{
  pQ->Front = -1;
  pQ->Rear = -1;

}

int main()
{
  int avgWait, soKhachHang, soQuay, tg1giaoDich, tgTbKhachHangDen, maxWait;
  scanf("%d", &soKhachHang);
  scanf("%d", &soQuay);
  scanf("%d", &tg1giaoDich);
  scanf("%d", &tgTbKhachHangDen);
  scanf("%d", &maxWait);

  for (int i = 1; avgWait != -1 && avgWait > maxWait && i <= soQuay; i++)
  {
    Queue listQuay[i + 1];
    
  }
}