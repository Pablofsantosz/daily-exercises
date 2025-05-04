def encontrar_indices(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                print(f"Índices encontrados: [{i}, {j}]")
                return
    print("Nenhuma combinação encontrada.")

def main():
    target = int(input("Informe o número target: "))
    tam = int(input("Informe o tamanho do vetor:"))
    vetor = []
    print("Agora informe os valores dentro do vetor:")
    for i in range(tam):
        valor = int(input(f"Valor na posição [{i}]: "))
        vetor.append(valor)
    
    encontrar_indices(vetor, target)

if __name__ == "__main__":
    main()
