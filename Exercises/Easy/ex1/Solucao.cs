using System;
using System.Globalization;

namespace Course
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.Write("Informe um target :");
            int target= int.Parse(Console.ReadLine());

            Console.Write("Informe agora o tamanho do vetor :");
            int tam = int.Parse(Console.ReadLine());

            int[] vetor = new int[tam];
            Console.WriteLine("informe os valores dentro do vetor:");
            for(int i = 0; i < tam; i++)
            {
                Console.Write($"valor na posição[{i}]:");
                vetor[i]= int.Parse(Console.ReadLine());
            }

            int[] indices = Metodo.EncontrarIndicesSoma(vetor,tam,target);
            if (indices != null)
            {
                Console.WriteLine($"\nOs índices encontrados são: [{indices[0]}, {indices[1]}]");

            }
            else
            {

                Console.WriteLine("\nNenhum par de números soma o target informado.");
            }


        }
    }
}

namespace Course
{
    class Metodo
    {
        
        public static int[] EncontrarIndicesSoma(int[] V, int tam, int target)
        {
            for (int i = 0; i < tam; i++)
            {
                for (int j = i + 1; j < tam; j++)
                {
                    if (V[i] + V[j] == target)
                    {
                        return   new int[] { i, j } ;
                    }
                }
            }
            return null;
        }

    }
}