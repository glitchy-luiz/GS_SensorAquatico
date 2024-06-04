<p align="center">
 <h1 align="center">AquaSensor</h1>
 <p align="center">O novo projeto de captura de informações da água</p>
</p>

## Introdução
Este é nosso projeto em c++ com arduino em que visamos solucionar o problema de falta e dificuldade a acesso e informação sobre as águas do oceano. O projeto foi originalmente feito do Wokwi, junto com a simulação. Para ver a simulação entre no link: https://wokwi.com/projects/399793052773957633

## 1- Array de dados:
No inicio do projeto temos 3 arrays que tem informações que serão exibidas para o usuário conforme a nessecidades passadas nas funções, as listas contem as orientações para os devidos tratamentos de água

```md
infos = ['ph', 'temp', 'sal']
tratbaixo = ['utilize um elevador de ph na área', 'Retirar a vida marinha da área enquanto limpa os residuos de lixo na superficie da água', 'Adicione uma solução salina na água']
tratalto = ['use a adição de um ácido fraco ou de um ácido forte diluído na água','Analise as correntes de água da área de acordo com a época do ano','adicione água salina magnetizada na área analisada']
```

## 2- Função inicial:
Ao rodar o código, a primeira coisa que aparecera para o usuario é uma mensagem de boas vindas e logo em sequência, chamará a função 'analisaragua'

```md
print('Bem-vindo ao WaterStats!')
analisaragua()
```

Nela, pediremos informações sobre a água através de inputs e chamaremos a função para verificar se a resposta é um número
> **Note**
> A variavel que guarda a resposta do user é passada como parametro

```md
def analisaragua ():
    ph = input('Digite o ph da água: ')
    novoph = verificarnum(ph)
    temp = input('Digite a temperatura da água(Celcius): ')
    novotemp = verificarnum(temp)
    sal = input('Digite a salinidade da água(grama/litro): ')
    novosal = verificarnum(sal)
```

A função que verifica se a resposta é um número é feita por um loop while que só é satisfeito caso a resposta seja númerica

```md
def verificarnum(numero):
    while not numero.isnumeric():
        numero = input('Diga um numero valido: ')
    return int(numero)
```

## 3- Verificando as váriaveis:
Na função 'analisaragua' nós passamos as respostas como parametro para uma outra função

```md
    aguaverificada = verificaragua(novoph, novotemp, novosal)
```

essa função é responsavel para verificar se os padrões da água estão bons, altos, ou baixos, passando por uma série de 'if' e no fim mostrando os resultados para o usuário por meio de um 'print'

```md
def verificaragua(ph,temp,sal):
    nivelph = ''
    niveltemp = ''
    nivelsal = ''
    if ph >= 7 and ph <= 9:
        nivelph = 'bom'
    elif ph < 7:
        nivelph = 'baixo'
    else:
        nivelph = 'alto'

    if temp >= 5 and temp <= 15:
        niveltemp = 'bom'
    elif temp < 5:
        niveltemp = 'baixo'
    else:
        niveltemp = 'alto'

    if sal >= 30 and sal <= 40:
        nivelsal = 'bom'
    elif sal < 30:
        nivelsal = 'baixo'
    else:
        nivelsal = 'alto'

    print(f'Detalhes da água:\n - PH: {ph}, nivel: {nivelph}\n - Temperatura: {temp}°C, nivel: {niveltemp}\n - Salinidade: {sal} gramas/litro, nivel: {nivelsal}')

    return [nivelph, niveltemp, nivelsal]
```
e retornando uma lista com os valores do niveis da água

## 4- Tratamento
Na função de 'analisaragua' perguntamos se o user quer ver as orientações, e verificamos se a resposta foi sim ou não usando uma nova função com a mesma lógica do 'verificarnum'. E caso a resposta seja 'sim', chamamos a função para tratar a água

```md
 orientacoes = input('Você quer ver as orientações sobre como tratar a água?(Diga "sim" ou "não"): ')
    resposta = verificarsimounao(orientacoes)

    if resposta == 'sim':
        tratamento(aguaverificada)
```
```md
def verificarsimounao(res):
    while not (res == 'sim' or res == 'não'):
        res = input('Diga "sim" ou "não": ')
    return res
```

Na função do tratamento temos um loop for, que passa por todos os itens da lista de niveis da água retornada anteriormente, e verificando se os niveis estão baixos ou altos

```md
def tratamento (lista):
    for i in range(len(lista)):
        if lista[i] == 'baixo':
            print(f'tratamento de {infos[i]} ({lista[i]}) \n - Orientação: {tratbaixo[i]} ')
        elif lista[i] == 'alto':
            print(f'tratamento de {infos[i]} ({lista[i]}) \n - Orientação: {tratalto[i]} ')
    return
```

Caso o nivel entre em alguma das condições, será passada uma mensagem explicando o que fazer nesta situação, as informações da mesangem são pegas de acordo com o indice da lista, nivel do indice, e dados das arrays passsadas no inicio do código

## 5- Finalização
Após passar o tratamento da água, perguntamos ao user na função 'analisaragua' se ele gostaria de repetir o processo com uma nova água, caso diga 'sim', o código se repetira

```md
repetir = input('Você quer analisar outra água?(Diga "sim" ou "não"): ')
    repeticao = verificarsimounao(repetir)

    if repeticao == 'sim':
        analisaragua()
```
e após isto, damos uma pequena mensagem de adeus, e terminamos o código
```md
print('Até mais')
```

INTEGRANTES:
- Luiz Fernando Souza RM: 555561
- Bruno Otavio RM:556196
