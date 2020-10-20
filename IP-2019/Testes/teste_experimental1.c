#include <stdio.h>

float velocidade(int nKm, float td)
{
    float KmH;
    int tdh;
    tdh = td;
    td = td - tdh;
    td = td * 100/60;
    td += tdh;
    KmH = nKm / td;

    return(KmH);
}

void main()
{
    int nFunc, func, nTraj, traj, nKm;
    float KmH, vM, td;

    printf("Numero de funcionarios > ");
    scanf("%d",&nFunc);

    func = 1;

    while (func <= nFunc)
    {
        printf("\nFuncionario: %.2d\n",func);
        printf("\nNumero de trajetos > ");
        scanf("%d",&nTraj);

        traj = 1;
        vM = 0;

        while (traj <= nTraj)
        {
            printf("\nTrajeto %.2d",traj);
            printf("\nQuilometros percorridos e tempo decorrido > ");
            scanf("%d %f",&nKm,&td);
            KmH = velocidade(nKm,td);

            if (KmH<30)
                printf("Abaixo do limite minimo  %.2f\n",KmH);
            else if (KmH>120)
                printf("Acima do limite maximo  %0.2f\n",KmH);
            else
                printf("Velocidade no trajeto = %.2f\n",KmH);

            traj++;
            vM += KmH;
        }

        vM /= nTraj;
        printf("\nVelocidade media do funcionario = %.2f\n\n\n",vM);

        func++;
    }
}
