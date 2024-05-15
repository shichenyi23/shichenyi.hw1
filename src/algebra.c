/*
 * @Author: shichenyi shichenyi23@163.com
 * @Date: 2024-05-04 16:23:08
 * @LastEditors: shichenyi shichenyi23@163.com
 * @LastEditTime: 2024-05-05 17:34:25
 * @FilePath: \GitHub\shichenyi.hw1\src\algebra.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    Matrix c;
    int i,j;
    if(a.rows==b.rows&&a.cols==b.cols){
    c = create_matrix(a.rows,a.cols);
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=a.data[i][j]+b.data[i][j];
        }
    }
    return c;
    }
    else{
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    Matrix c;
    int i,j;
    if(a.rows==b.rows&&a.cols==b.cols){
    c = create_matrix(a.rows,a.cols);
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=a.data[i][j]-b.data[i][j];
        }
    }
    return c;
    }
    else{
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    Matrix c;
    int i,j,k;
    if(a.cols==b.rows){
        c = create_matrix(a.rows,b.cols);
        for(i=0;i<a.rows;i++){
            for(j=0;j<b.cols;j++){
                c.data[i][j]=0;
                for(k=0;k<a.cols;k++){
                    c.data[i][j]=c.data[i][j]+a.data[i][k]*b.data[k][j];
                }
            }
        }
        return c;
    }
    else{
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}
Matrix scale_matrix(Matrix a, double k)
{
    Matrix c;
    int i,j;
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=k*a.data[i][j];
        }
    }
    return c;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix c;
    int i,j;
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=a.data[j][i];
        }
    }
    return c;
}

double det_matrix(Matrix a)
{
    double sum=0;
    int i,a,b,c;
    Matrix M;
    if(a.rows==a.cols){
        if(a.rows==1){
            sum=a.data[0][0];
        }
        else if(a.rows>1){
            M=create_matrix(a.rows-1,a.cols-1);
            for(i=0;i<a.rows-1;i++){
                
            }
            for(i=0;i<a.rows;i++){
                sum+=((i+2)%2?-1:1)*1
            }
        }
    }
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    double tr=0;
    int i;
    if(a.rows==a.cols){
        for(i=0;i<a.rows;i++){
            tr=tr+a.data[i][i];
        }
        return tr;
    }
    else{
        return 0;
    }
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}