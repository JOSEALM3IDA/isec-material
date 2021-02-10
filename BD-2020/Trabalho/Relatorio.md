![ISEC Logo](https://moodle.isec.pt/moodle/pluginfile.php/1/theme_adaptable/logo/1581343866/logo.png)

Instituto Politécnico de Coimbra

Instituto Superior de Engenharia de Coimbra

Departamento de Engenharia Informática e de Sistemas

Licenciatura de Engenharia Informática | Licenciatura de Engenharia Informática (Curso Europeu)

Bases de Dados

2020/2021

---

## **Cap 1: Tema**

*Sistema de Entregas de Comida/Objetos Diversos*

---

## **Cap 2: Identificação dos Autores**

| Nº Aluno | Prática | Nome | Email |
| --- | --- | --- | --- |
| xxxxxxxxxx | P4 | ianmooone | xxxxxxxxx@isec.pt |
| xxxxxxxxxx | P2 | TheForgotten | xxxxxxxxxxx@isec.pt |
| xxxxxxxxxx | P6 | JOSEALM3IDA | xxxxxxxxxxx@isec.pt |

A comunicação é maioritariamente efetuada pelo serviço "Discord" e, para o trabalho em si, é usado o source control "GitHub" para podermos estar sempre sincronizados e acompanhar as mudanças que cada um faz.

| Tarefa | ianmooone | TheForgotten | JOSEALM3IDA |
| --- | --- | --- | --- |
| Análise da Situação Atual | 33.33% | 33.33% | 33.33% |
| Tarefa 2 | 33.33% | 33.33% | 33.33% |
| Meta 1 | 33.33% | 33.33% | 33.33% |

---

## **Cap 3: Introdução**

O objetivo deste projeto é a implementação de um sistema que permita efetuar, de forma automatizada, a gestão de entregas de comida/objetos diversos. Esse sistema deve conter a lista de lojas aderentes ao sistema de entregas, assim como toda a informação sobre empregados e clientes, hora e local de entrega, objetos/comida disponível para encomenda, etc.

A empresa de entregas Inovação Sensacional de Entrega de Coisas, ou seja **ISEC**, veio introduzir-se no mercado em 2020, durante a pandemia, para facilitar a compra de coisas de tamanho relativamente simpático. A ideia surgiu após ser observada a desgraça que eram as empresas de entregas existentes. Não só eram demoradas, como não tinham os devidos cuidados higiénicos. Fundada por António P. Linha e Acácio Tesla no mês de março, esta tem-se mostrado super eficiente e inovadora no mundo das entregas. Como dizem todos os clientes, *"Isto era mesmo o que precisávamos, porra!"*.

---

## **Cap 4: Enquadramento da Proposta**
### **Sec 4.1: Diagnóstico da Situação Atual**

Atualmente, as bases de dados usadas para sistemas semelhantes não são eficientes e não sustentam um elevado e súbito fluxo de clientes. Com o avanço das tecnologias, é agora possível a atualização dos sistemas, criando uma base de dados que supere vários dos problemas de implementação atuais.

### **Sec 4.2: Problemas encontrados**

Um dos problemas atuais é que os sistemas não são eficientes o suficiente para habilitar o rápido crescimento dos mesmos, isto é, com o exponencial crescimento fluxo de clientes e consequente uso intensivo do sistema (como, por exemplo, numa situação de quarentena), o mínimo erro de implementação das rudimentares bases de dados torna-as rapidamente obsoletas.

Para além disto, devido ao facto de estarem extremamente desatualizadas, torna-se difícil o desenvolvimento de novas aplicações para interagir com as mesmas, o que se pode resolver, em grande parte, com a atualização da base de dados para uma arquitetura mais recente.

Com a base de dados atual, o processamento de cada pedido é, por vezes, demorado pois é realizado manualmente devido ao facto de, como foi dito anteriormente, estas serem extremamente rudimentares. Com a automatização e desenvolvimento usando a nova arquitetura, este problema será totalmente erradicado.

Outra falha crassa na corrente base de dados é a dificuldade na interação cliente-estafeta. Com a nossa proposta, este problema seria resolvido pois seria possível o desenvolvimento de aplicações que comunicassem o pedido do cliente diretamente ao entregador, eliminando, assim, o intermediário, que não só pode cometer erros como também atrasa o processo.

---

### **Sec 4.3: Descrição da Solução Proposta**

A solução passa por criar uma base de dados, fazendo recurso às ferramentas disponíveis atualmente, que possa ser usada por várias aplicações, de forma simples e intuitiva, pemitindo assim a automatização e uma experiência mais amigável ao utilizador comum, com acesso, da parte do cliente, por exemplo, à sua lista de encomendas terminadas ou em curso.

Deve ser também capaz de dar ao estafeta um rápido e fácil acesso às encomendas ainda não respondidas e aos veículos disponíveis para a sua realização.

A nossa base de dados vai conter, pelo menos, uma lista de lojas aderentes, de clientes, de estafetas, de encomendas realizadas ou em curso e de veículos disponíveis aos estafetas.

Para utilizar esta base de dados deve ser criada uma aplicação que, dependedo de quem está a aceder, mostre informação relevante. Por exemplo, se for o cliente a aceder esta deve mostrar deve ter uma interface onde pode aceder à seguinte informação:

- Encomendas realizadas por este, com a data e a hora exata das mesmas;
- Estafeta associado à sua encomenda e o local onde se encontra atualmente;
- Lojas de onde pode encomendar e que produtos estas têm disponíveis, assim como o seu preço e tempo de espera estimado;
- Seu perfil, incluindo opções para mudar as suas informações pessoais e adicionar/alterar locais de entrega.
 
No caso de ser um estafeta a aceder à aplicação esta deve ter uma interface onde pode aceder à seguinte informação:
- Encomendas que já entregou;
- Encomendas que estão neste momento à espera de estafeta, com informação das lojas onde tem que ir para buscar o(s) produto(s), que produto(s) são, o total de distância que tem que percorrer e quanto vai receber pelo entrega;
- Seu perfil, com opção para mudar informações pessoais e onde poderá ver qual o seu veículo, a matricula e o tipo do mesmo e ainda qual é o seu salário base e quanto é que já ganhou em taxas no presente mês.

Há também possibilidade de entrar na aplicação com uma conta única admin que tem um acesso mais direto à base de dados. Com esta conta devemos ter acesso a:

- Lista de estafetas registados na aplicação;
- Lista de clientes registados na aplicação;
- Lista de pessoas registadas na aplicação (independentemente de ser trabalhador ou cliente) com informação mais pessoal sobre cada um;
- Lista de veículos associados à empresa.

---

## **Cap 5: Funcionalidades da Aplicação**
### **Sec 5.1: Estrutura da Aplicação**

A aplicação deve utilizar uma arquitectura cliente/servidor que irá questionar o servidor de base de dados para aceder à informação desejada. Esta aplicação será instalada no telemóvel de cada utilizador, sendo o acesso à base de dados efectuado através da utilização de drivers nativos do Oracle.

Para permitir futuras evoluções, esta deve estar estruturada de uma forma modular, que permita facilmente adicionar novos módulos à aplicação. A utilização de uma arquitectura modular irá permitir a implementação faseada dos vários módulos que são propostos, e a possibilidade de futuramente ser possível adicionar novos, além dos já existentes, na mesma interface comum. Esta modularidade permitirá evitar a existência de várias aplicações, com objectivos distintos, mas que necessariamente irão possuir funcionalidades redundantes.

A aplicação deve ser constituída por um conjunto de módulos que permitam manipular os dados de cada uma das operações da ISEC. A cada operação deve corresponder um módulo da aplicação que será responsável por interagir com o utilizador e manipular os dados das tabelas associadas à operação em causa. Deve ter uma interface simples e agradável, em que o acesso a cada um dos módulos da aplicação esteja acessível através de um menu. Deve existir na interface principal um conjunto de atalhos que permita o acesso rápido aos módulos mais utilizados.

Os módulos a implementar para a interface do cliente são os seguintes:

- Acesso a lojas e aos produtos por estas vendidos;
- Acesso ao carrinho atual:
    - Gestão da quantidade e dos produtos (ambos nunca NULL).
- Acesso à lista de encomendas realizadas:
    - Acesso ao estado (obrigatoriamente não NULL);
    - Acesso à data de realização (obrigatoriamente não NULL);
    - Acesso à data de entrega (apenas se esta já se encontrar finalizada);
    - Acesso à localização atual do estafeta escolhido para entrega (se esta ainda não se encontrar finalizada);
    - Acesso ao método de pagamento usado (obrigatoriamente não NULL);
    - Acesso à lista de produtos encomendados, o respetivo preço, quantidade e a loja donde estes vieram (obrigatoriamente não NULL);
    - Acesso à taxa de entrega e ao valor total da encomenda (obrigatoriamente não NULL);
    - Acesso ao nome do estafeta escolhido para entrega (obrigatoriamente não NULL);
    - Acesso ao NIF associado à encomenda (que pode existir ou não);
    - Acesso ao local escolhido para entrega (obrigatoriamente não NULL).
- Acesso ao perfil:
    - Gestão de dados pessoais, onde apenas o email é opcional;
    - Gestao de locais de entrega, que podem existir ou não na conta, mas que são obrigatórios adicionar no caso de querer fazer uma encomenda.

Os módulos a implementar para a interface do estafeta são os seguintes:

- Acesso a uma lista de encomendas sem estafeta associado:
    - Acesso às lojas e aos produtos a entregar (obrigatoriamente não NULL);
    - Acesso ao total de distância que vai percorrer (obrigatoriamente não NULL);
    - Acesso a quanto vai receber de taxa de entrega (obrigatoriamente não NULL).
- Acesso a uma lista de entregas que já realizou:
    - Acesso ao estado (obrigatoriamente não NULL);
    - Acesso à data de realização (obrigatoriamente não NULL);
    - Acesso a quanto ganhou de taxa (obrigatoriamente não NULL).
- Acesso ao perfil:
    - Gestão de dados pessoais (obrigatoriamente não NULL exceto Email);
    - Acesso ao salário base (obrigatoriamente não NULL);
    - Acesso a quanto recebeu de taxa no presente mês (obrigatoriamente não NULL);
    - Acesso ao veículo associado a este, com matrícula, modelo e tipo de veículo (campos obrigatoriamente não NULL).

Os módulos a implementar para a interface do admin seguem as regras já descritas acima quanto a possibilidade de serem NULL ou não. São os seguintes:

- Acesso a uma lista de clientes:
    - Acesso aos ID respetivos (primary key);
    - Acesso aos nomes respetivos;
    - Acesso a quantos locais de entrega tem guardados;
    - Acesso ao número de encomendas que este já realizou.
- Acesso a uma lista de estafetas:
    - Acesso aos ID respetivos (primary key);
    - Acesso aos nomes respetivos; 
    - Acesso ao estado;
    - Acesso ao último local onde esteve de serviço;
    - Acesso ao salário base.
- Acesso a uma lista de pessoas (todos os utilizadores da app, sejam clientes ou estafetas):
    - Acesso aos ID respetivos (primary key);
    - Acesso aos nomes e emails respetivos;
    - Acesso aos números de telemóvel respetivo.
- Acesso a uma lista de veículos:
    - Acesso às matrículas respetivas (primary key);
    - Acesso aos modelos respetivos (obrigatoriamente não NULL);
    - Acesso à disponibilidade (obrigatoriamente SIM ou NÃO).

### **Sec 5.2: Módulos da aplicação e protótipos**

#### **Ecrã de loading, login e registo**

![Loading](https://i.imgur.com/zfSRW8g.png)
![Login](https://i.imgur.com/ZyQdQaN.png)
![Register](https://i.imgur.com/Np4zUX2.png)

O ecrã de loading é o ecrã que se vê enquanto a aplicação carrega.

O ecrã de login é o ecrã onde se faz login para uma conta de utilizador, independentemente desta ser cliente ou estafeta. O Nº de Telemóvel é obrigatório e a Password também.

O ecrã de registo é o ecrã onde se regista uma nova conta de utilizador. É obrigatorio Nome, Nº de Telemóvel, Password e um tipo de utilizador (por defeito será cliente).

#### **Ecrã home do cliente**

![Home_Cliente](https://i.imgur.com/SCdnkzq.png)
![Expandido](https://i.imgur.com/IN5SXr4.png)

Este é o ecrã apresentado ao cliente após fazer login. Apresenta ao cliente várias lojas, divididas por secções consoante o tipo de produtos que vendem (a divisão é definida pela entidade TipoLoja).

Apresenta também um dropmenu onde o cliente tem a opção de escolher qual o local de entrega predefinido dos que já adicionou à sua conta a partir do ecrã Conta.

Por fim, apresenta também uma pequena descrição do carrinho e dá opção ao cliente para expandir o carrinho e ver informação mais detalhada sobre o mesmo e também a opção de finalizar o pedido.

#### **Ecrã pesquisar do cliente**

![Pesquisar_Cliente](https://i.imgur.com/O7mHLAp.png)
![Expandido](https://i.imgur.com/IN5SXr4.png)

Este é o ecrã de pesquisa do cliente. Aqui este tem opção de pesquisar no catálogo por produtos, lojas ou até mesmo por localidade. Para além disso, pode também escolher como pretende ordenar os resultados obtidos.

Por fim, tal como no anterior, apresenta também uma pequena descrição do carrinho e dá opção ao cliente para expandir o carrinho e ver informação mais detalhada sobre o mesmo e também a opção de finalizar o pedido.

#### **Ecrã de loja do cliente**

![Loja](https://i.imgur.com/f1pH0Cz.png)
![Expandido](https://i.imgur.com/IN5SXr4.png)

Este é o ecrã de loja que aparece ao cliente quando este seleciona uma. Aqui tem acesso a todo o catálogo da loja e o respetivo preço de cada produto, podendo adicionar ao carrinho simplesmente ao clicar no (+) do lado deste.

Por fim, tal como no anterior, apresenta também uma pequena descrição do carrinho e dá opção ao cliente para expandir o carrinho e ver informação mais detalhada sobre o mesmo e também a opção de finalizar o pedido.

#### **Ecrã de encomendas do cliente**

![Encomendas](https://i.imgur.com/L3OOGs4.png)
![Encomendas](https://i.imgur.com/2crLrWA.png)
![Encomendas](https://i.imgur.com/f0o2SNL.png)

Este é o ecrã de encomenda do cliente. Aqui tem acesso a todas as encomendas que já realizou.

Ao clicar na encomenda tem acesso a informação mais detalhada sobre a encomenda. No caso de este ainda estar a decorrer tem acesso a uma interface como a da segunda imagem onde consegue ver o carrinho, os produtos que encomendou, quanto pagou, o local que escolheu para entrega, o NIF escolhido para a encomenda, o método de pagamento usado, data exata de quando a encomenda foi submetida, nome do estafeta e a sua localização num mapa que tem o estafeta, o ponto de entrega e a loja ou lojas onde este que tem que ir levantar os produtos. No caso de esta já estar terminada o cliente tem acesso a uma interface como a da terceira imagem onde consegue ver o carrinho, os produtos que encomendou, quanto pagou, o local que escolheu para entrega, o NIF escolhido para a encomenda, o método de pagamento usado, data exata de quando a encomenda foi submetida, data exata de quando foi entregue e o nome do estafeta que entregou.

#### **Ecrã conta do cliente**

![Conta](https://i.imgur.com/UmcqVNX.png)

Este é o ecrã de conta do cliente.

Aqui o cliente pode consultar e alterar informação pessoal como o nome, o nº de telemóvel, o email e a password.

Para além disso pode também alterar/adicionar locais de entrega novos.

#### **Ecrã finalizar encomenda do cliente**

![Finalizar](https://i.imgur.com/kubtedA.png)

Este é o ecrã para finalizar encomendas para o cliente.

Aqui consegue ver o carrinho, os produtos que colocou neste, quanto vai pagar por cada e pode escolher o local para entrega, o NIF para associar à encomenda e o método de pagamento que pretende usar.

#### **Ecrã home do estafeta**

![Home](https://i.imgur.com/q5CvXwF.png)

Este é o ecrã principal da interface para estafeta.

Aqui o estafeta tem acesso a uma lista de encomendas que ainda não foram aceites por outros estafetas. Estas mostram as lojas e quais os produtos e as quantidades a trazer de cada produto. Para além disto mostra também a distância a percorrer e quanto irá receber por realizar aquele serviço e um botão aceitar para ficar responsável pela entrega daquela encomenda.

#### **Ecrã de entregas do estafeta**

![Encomendas](https://i.imgur.com/P1TTl4q.png)

Este aqui é o ecrã de entregas realizadas pelo estafeta.

Aqui consegue ver a data de realização da encomenda, o estado desta e quanto recebeu ao realizá-la.

#### **Ecrã de pagamentos do estafeta**

![Encomendas](https://i.imgur.com/H46MApm.png)

Este aqui é o ecrã de pagamentos que foram efetuados ao estafeta pela empresa.

Aqui consegue ver a data de realização do pagamento e quanto foi pago.

#### **Ecrã conta do estafeta**

![Conta](https://i.imgur.com/9Rt1cNc.png)

Este aqui é o ecrã de conta do estafeta.

Aqui o estafeta pode consultar e alterar informação pessoal como o nome, o nº de telemóvel, o email e a password.

Para além disso consegue também ver o seu salário base, o total de taxas que já juntou no presente mês e o veículo que este usa com modelo, matrícula e tipo.

#### **Ecrã estafetas do admin**

![Estafetas](https://i.imgur.com/4AiD4AD.png)

Este aqui é o ecrã de estafetas para o admin.

Aqui o admin consegue ver uma lista de todos os utilizadores do tipo estafetas registados na aplicação e os respetivos ID, Nome, estado, o último local registado e o salário base, assim como efetuar e ordenar pesquisas por esses mesmos atributos.

#### **Ecrã pagamentos do admin**

![Estafetas](https://i.imgur.com/u9LWY9V.png)

Este aqui é o ecrã de pagamentos para o admin.

Aqui o admin consegue ver uma lista de todos os pagamentos realizados pela empresa, a data em que foram realizados, qual foi o montante pago e o ID deste pagamento.

#### **Ecrã clientes do admin**

![Clientes](https://i.imgur.com/S4w41rq.png)

Este aqui é o ecrã de clientes para o admin.

Aqui o admin consegue ver uma lista de todos os utilizadores do tipo cliente registados na aplicação e os respetivos ID, Nome, número de locais de entrega e número de encomendas já realizadas, assim como efetuar e ordenar pesquisas por esses mesmos atributos.

#### **Ecrã veículos do admin**

![Veículos](https://i.imgur.com/88K6AlY.png)

Este aqui é o ecrã de veiculos para o admin.

Aqui o admin consegue ver uma lista de todos os veículos que pertencem à empresa e a respetiva matrícula, modelo e a disponibilidade, assim como efetuar e ordenar pesquisas por esses mesmos atributos.

---

## **Cap 6: Análise de Dados**

### **Sec 6.1: Entidades**

Nesta secção vão ser descritas todas as entidades relevantes para o negócio de entregas de produtos diversos. Após uma análise aprofundada do modelo de negócio destes sistemas, constatou-se a necessidade das seguintes entidades:

- Locais de Entrega
- Cliente
- Estafeta
- Pagamento
- Veículo
- Encomendas
- Estados
- Entrega
- Métodos Pagamento
- Produtos
- Marcas
- Lojas

#### **Sec 6.1.1: Entidade Locais de Entrega**

A entidade locais de entrega representa a informação relativa aos locais de entrega existentes na base de dados. Cada local de entrega é associado a um e um só cliente, apesar de poderem existir vários locais de entrega com a mesma morada. É inserido um novo registo sempre que um cliente associa à sua conta um novo local de entrega.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Local | Number (8) | Contém um ID único para o local de entrega <br> <b>Exemplo:</b> 00000122 |
| Rua | Var. char. (200) | Contém o nome da rua da morada associada ao local de entrega <br> <b>Exemplo:</b> R. Pedro Nunes |
| Numero Porta | Number (4) | Contém o número da porta da morada associada ao local de entrega <br> <b>Exemplo:</b> 052 |
| Andar | Number (2) | Contém o andar (caso seja usado) da morada associada ao local de entrega <br> <b>Exemplo:</b> 04 |
| Codigo Postal | Number (7) | Contém o código postal da morada associada ao local de entrega <br> <b>Exemplo:</b> 3030193 |
| Cidade | Var. char. (50) | Contém o nome da cidade da morada associada ao local de entrega <br> <b>Exemplo:</b> Coimbra |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Local | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois locais de entrega com o mesmo ID |
| Rua | Não | Não | Podem existir dois locais de entrega com a mesma rua |
| Numero Porta | Não | Não | Podem existir duas moradas completamente diferentes que partilhem o número de porta |
| Andar | Sim | Não | Podem existir duas moradas completamente diferentes que partilhem o andar |
| Codigo Postal | Não | Não | Podem existir várias moradas com o mesmo código postal |
| Cidade | Sim | Não | Podem existir várias moradas na mesma cidade |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Pertence a | 1:N | Cliente | Locais de Entrega |
| Entregue em | 1:N | Encomendas | Locais de Entrega |

#### **Sec 6.1.2: Entidade Cliente**

A entidade cliente representa a informação relativa aos clientes registados na aplicação. É inserido um novo registo sempre que um novo cliente se regista na plataforma.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Cliente | Number (8) | Contém um ID único para o cliente <br> <b>Exemplo:</b> 00000856 |
| Nome | Var. char. (50) | Contém o nome do cliente <br> <b>Exemplo:</b> Nuno António Simões de Almeira |
| Data Nascimento | Date | Contém a data de nascimento do cliente <br> <b>Exemplo:</b> 05-FEV-1976 |
| Telemóvel | Number (9) | Contém o número de telemóvel do cliente <br> <b>Exemplo:</b> 919191919 |
| Email | Var. char. (50) | Contém o email do cliente <br> <b>Exemplo:</b> email.exemplo@nowhere.co.uk |
| Foto_URL | Var. char. (100) | Contém um URL para uma foto do cliente <br> <b>Exemplo:</b> https://i.imgur.com/6SH67go.png |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Cliente | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois clientes com o mesmo ID |
| Nome | Não | Não | Podem existir dois clientes com o mesmo nome |
| Data Nascimento | Não | Não | Podem existir dois clientes com a mesma data de nascimento |
| Telemóvel | Sim | Sim | Não é possível existirem dois cliente com o mesmo número de telemóvel |
| Email | Não | Sim | Não podem existir dois clientes com o mesmo email |
| Foto_URL | Sim | Sim | Mesmo que a foto de dois clientes seja a mesma, o URL será único |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Pertence a | 1:N | Locais de Entrega | Locais de Entrega |
| Feita por | 1:N | Encomendas | Encomendas |

#### **Sec 6.1.3: Entidade Estafeta**

A entidade estafeta representa a informação relativa aos estafetas registados na aplicação. É inserido um novo registo sempre que um novo estafeta se regista na plataforma.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Estafeta | Number (8) | Contém um ID único para o estafeta <br> <b>Exemplo:</b> 00000788 |
| Nome | Var. char. (50) | Contém o nome do estafeta <br> <b>Exemplo:</b> Bruno António Silva de Almeira |
| Data Nascimento | Date | Contém a data de nascimento do estafeta <br> <b>Exemplo:</b> 05-JAN-1976 |
| Telemóvel | Number (9) | Contém o número de telemóvel do estafeta <br> <b>Exemplo:</b> 969696969 |
| Email | Var. char. (50) | Contém o email do estafeta <br> <b>Exemplo:</b> email.exemplo@nowhere.co.uk |
| Posição | Var. char. (50) | Contém a localização atual do estafeta <br> <b>Exemplo:</b> R. Nuno Pires, Coimbra |
| Comissão por Pagar | Money | Contém o valor que a empresa está a dever a este estafeta  <br> <b>Exemplo:</b> 24 |
| Foto_URL | Var. char. (100) | Contém um URL para uma foto do estafeta <br> <b>Exemplo:</b> https://i.imgur.com/6SH67go.png |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Estafeta | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois estafetas com o mesmo ID |
| Nome | Não | Não | Podem existir dois estafetas com o mesmo nome |
| Data Nascimento | Não | Não | Podem existir dois estafetas com a mesma data de nascimento |
| Telemóvel | Não | Sim | Não é possível existirem dois estafetas com o mesmo número de telemóvel |
| Email | Não | Sim | Não podem existir dois estafetas com o mesmo email |
| Posição | Não | Não | Podem estar dois estafetas no mesmo local |
| Comissão por Pagar | Não | Não | Dois estafetas diferentes podem ter o mesmo valor por receber |
| Foto_URL | Não | Sim | Mesmo que a foto de dois estafetas seja a mesma, o URL será único |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Pagamento Comissões | 1:N | Pagamento | Estafeta |
| Conduz | 1:1 | Veículo | N/A |
| Entregue por | 1:N | Entrega | Estafeta |
| Escolha | 1:N | Encomendas | Estafeta |

#### **Sec 6.1.4: Entidade Pagamento**

A entidade pagamento representa a informação relativa aos aos pagamentos realizados ao estafeta. É inserido um novo registo sempre que é realizado um pagamento.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Pagamento | Number (8) | Contém um ID único para o estafeta <br> <b>Exemplo:</b> 00000663 |
| Montante | Money | Contém o que foi pago ao estafeta neste pagamento <br> <b>Exemplo:</b> 24 |
| Data Pagamento | Date | Contém a data do pagamento <br> <b>Exemplo:</b> 05-JAN-2021 |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Pagamento | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois pagamentos com o mesmo ID |
| Montante | Não | Não | Podem existir dois pagamentos com o mesmo valor |
| Data Pagamento | Não | Não | Podem ser realizados dois pagamentos na mesma data, deve ser inferior ou igual à SYSDATE |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Pagamento Comissões | 1:N | Pagamento | Estafeta |

#### **Sec 6.1.5: Entidade Veículo**

A entidade veiculo representa a informação relativa aos veículos que pertencem à empresa. Cada veículo só pode ser conduzido por um estafeta de cada vez. É inserido um novo registo sempre que é adquirido um novo veículo.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| Matrícula | Var. char. (10) | Contém a matrícula do veículo <br> <b>Exemplo:</b> 89-HR-45 |
| Tipo Veículo | Var. char. (20) | Contém o tipo de veiculo que é <br> <b>Exemplo:</b> Scooter |
| Disponibilidade | Boolean | Contém informação sobre se o veículo está disponível ou não <br> <b>Exemplo:</b> 1 |
| Modelo | Var. char. (20) | Contém o modelo do veículo <br> <b>Exemplo:</b> Speedfight 2 |
| Marca | Var. char. (20) | Contém a marca do veículo <br> <b>Exemplo:</b> Peugeot |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| Matrícula | Não | Sim | Como as matrículas são únicas estas sao usadas como primary key, não admite nulos |
| Tipo Veículo | Sim | Não | Não é obrigatório mencionar o tipo de veículo e há vários veículos do mesmo tipo |
| Disponibilidade | Não | Não | Tem que estar sempre preenchida com "SIM" ou "NÃO", sendo "SIM" o default |
| Modelo | Não | Não | A empresa pode possuir vários veículos do mesmo modelo |
| Marca | Não | Não | A empresa pode possuir vários veículos da mesma marca |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Conduz | 1:1 | Veículo | N/A |

#### **Sec 6.1.6: Entidade Encomendas**

A entidade encomendas representa a informação relativa às encomendas realizadas por clientes na empresa.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Encomenda | Number (8) | Contém um ID único para a encomenda <br> <b>Exemplo:</b> 00004636 |
| Taxa Entrega | Money | Contém o valor da taxa de entrega <br> <b>Exemplo:</b> 1 |
| Data Encomenda | Date & Time | Contém a data e a hora em que a encomenda foi realizada <br> <b>Exemplo:</b> 19-JUL-2021 17:45:03 |
| NIF | Number (9) | Contém o NIF associado à encomenda <br> <b>Exemplo:</b> 123456789 |
| Data Entrega Desejada | Date & Time | Contém a hora que o cliente deseja em que a encomenda seja entregue <br> <b>Exemplo:</b> 19-JUL-2021 17:40:00 |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Encomenda | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois pagamentos com o mesmo ID |
| Taxa Entrega | Não | Não | Podem existir 2 ou mais encomendas com a mesma taxa de entrega |
| Data Encomenda | Não | Não | Podem ser realizadas várias encomendas à mesma hora |
| NIF | Sim | Não | Podem existir várias encomendas com o mesmo NIF e não é obrigatório atribuir NIF a uma encomenda |
| Data Entrega Desejada | Não | Não | Podem existir 2 ou mais encomendas com a mesma data de entrega desejada |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Entregue em | 1:N | Locais de Entrega | Locais de Entrega |
| Escolha | 1:N | Estafeta | Estafeta |
| Feita por | 1:N | Cliente | Encomendas |
| Associa | 1:1 | Entrega | Entrega |
| Paga Usando | 1:N | Métodos Pagamento | Encomendas | 
| Encontra-se | 1:N | Estados | Encomendas |
| Contêm | 1:N | Produtos | Encomendas |

#### **Sec 6.1.7: Entidade Estados**

A entidade estados contém os vários estados que uma encomenda pode ter.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Estado | Number (8) | Contém um ID único para o estado <br> <b>Exemplo:</b> 00006363 |
| Nome Estado | Var. char. (30) | Contém o nome do estado <br> <b>Exemplo:</b> A processar |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Estado | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois estados com o mesmo ID |
| Nome Estado | Não | Não | Diferentes estados não podem possuir o mesmo nome |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Encontra-se | 1:N | Encomendas | Encomendas |

#### **Sec 6.1.8: Entidade Entrega**

A entidade entrega contém informação sobre uma entrega associaca a uma encomenda.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Entrega | Number (8) | Contém um ID único para a entrega <br> <b>Exemplo:</b> 00005896 |
| Data Entrega | Date | Contém a data da entrega <br> <b>Exemplo:</b> 18-JUN-2020 |
| Rating | Number (3,1) | Contém uma classificação dada, pelo cliente, ao serviço prestado pelo estafeta <br> <b>Exemplo:</b> 4.5 |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Entrega | Não | Sim | Identificador (chave primária), não admite nulos, não existem duas entregas com o mesmo ID |
| Data Entrega | Não | Não | Podem existir duas entregas feitas na mesma hora |
| Rating | Sim | Não | Várias encomendas podem ter o mesmo rating, não é obrigatório o cliente dar rating, o valor da rating deve estar entre 0 e 5 |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Associa | 1:1 | Encomendas | Entrega |
| Entregue por | 1:N | Estafeta | Estafeta |

#### **Sec 6.1.9: Entidade Métodos Pagamento**

A entidade métodos pagamento contém os diferentes métodos de pagamento disponíveis no ato de pagamento duma encomenda.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| Nome Método | Var. char. (50) | Contém o nome (único) do método <br> <b>Exemplo:</b> PayPal |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| Nome Método | Não | Sim | Contém o nome (único) do método de pagamento, serve também de primary key |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Paga Usando | 1:N | Encomendas | Encomendas | 

#### **Sec 6.1.10: Entidade Produtos**

A entidade produtos contém os diferentes produtos disponíveis para encomenda.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Produto | Number (8) | Contém um ID único para o produto <br> <b>Exemplo:</b> 00046696 |
| Preco Tabela | Money | Contém o preço do produto <br> <b>Exemplo:</b> 1.90 |
| Nome Produto | Var. char. (30) | Contém o nome do produto <br> <b>Exemplo:</b> Shampoo Menta |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Produto | Não | Sim | Identificador (chave primária), não admite nulos, não existem dois produtos com o mesmo ID |
| Preco Tabela | Não | Não | Produtos diferentes podem ter o mesmo preço |
| Nome Produto | Não | Não | Podem existir produtos diferentes com o mesmo nome como, por exemplo, batatas fritas |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Contêm | 1:N | Encomendas | Encomendas |
| Têm determinada | 1:N | Marcas | Produtos & Marcas |
| Vende | 1:N | Lojas | Produtos |

#### **Sec 6.1.11: Entidade Marcas**

A entidade marcas contém as diferentes marcas associadas aos diferentes produtos e lojas que a empresa distribui.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Marca | Numer (8) | Contém um ID único para a marca <br> <b>Exemplo:</b> 00097596 |
| Nome Marca | Var. char. (30) | Contém o nome da marca <br> <b>Exemplo:</b> Lays |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Marca | Não | Sim | Identificador (chave primária), não admite nulos, não existem duas marcas com o mesmo ID |
| Nome Marca | Não | Não | Podem haver duas marcas com o memso nome (raro mas há chance de acontecer) |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Vendida em | 1:N | Lojas | Marcas & Lojas |
| Têm determinada | 1:N | Produtos | Produtos & Marcas |

#### **Sec 6.1.12: Entidade Lojas**

A entidade lojas contém as diferentes lojas associadas aos diferentes produtos e marcas que a empresa distribui.

Atributos relevantes da entidade:

| Nome do Atributo | Tipo de Dados | Descrição |
| --- | --- | --- |
| ID Loja | Number (8) | Contém um ID único para a loja <br> <b>Exemplo:</b> 00575963 |
| Tipo Loja | Var. char. (30) | Contém o tipo de loja <br> <b>Exemplo:</b> Mercearia |
| Localização | Var. char. (200) | Contém uma morada resumida da loja <br> <b>Exemplo:</b> Rua António Mota, Miranda do Corvo |
| Nome Loja | Var. char. (30) | Contém o nome da loja <br> <b>Exemplo:</b> MiniPreço |

Restrições dos atributos da entidade:

| Nome do Atributo | Aceita nulos? | Valores únicos? | Observações |
| --- | --- | --- | --- |
| ID Loja | Não | Sim | Identificador (chave primária), não admite nulos, não existem duas lojas com o mesmo ID |
| Tipo Loja | Sim | Não | Podem existir várias lojas do mesmo tipo e uma loja pode ser vaga ao ponto de não ter um tipo definido |
| Localização | Não | Não | Podem existir duas lojas na mesma localização (como foi dito em cima, é uma morada resumida e não uma morada completa) |
| Nome Loja | Não | Não | Podem existir duas lojas com o mesmo nome |

Relacionamentos da entidade:

| Nome do Relacionamento | Cardinalidade | Entidade Relacionada | Participação Obrigatória |
| --- | --- | --- | --- | 
| Vendida em | 1:N | Marcas | Marcas & Lojas |
| Vende | 1:N | Produtos | Produtos |

### **Sec 6.2: Relacionamentos**

Nesta secção vão ser descritas todas os relacionamentos relevantes para o negócio de entregas de produtos diversos. Após uma análise aprofundada do modelo de negócio destes sistemas, constatou-se a necessidade dos seguintes relacionamentos:

- Entregue Em
- Encontra-se
- Feita por
- Associa
- Escolha
- Paga usando
- Pagamento de comissões
- Entregue por
- Conduz
- Têm determinada
- Vendida em
- Vende
- Pertence a
- Contêm

#### **Sec 6.2.1: Entregue Em**

Este relacionamento destina-se a relacionar cada encomenda com o seu local de entrega. O objetivo é saber onde cada encomenda é entregue.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Locais de Entrega | Não | N:1 | Sim | Encomendas |

Observações:

- Uma encomenda tem obrigatoriamente um local de entrega
- Num local de entrega podem ser entregues várias encomendas

#### **Sec 6.2.2: Encontra-se**

Este relacionamento diz-nos qual o estado de cada encomenda.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Estados | Não | 1:N | Sim | Encomendas |

Observações:

- Uma encomenda tem um só estado
- Um estado pode estar associado a várias encomendas

#### **Sec 6.2.3: Feita por**

Este relacionamento diz-nos qual as encomendas realizadas por cada cliente.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Cliente | Não | 1:N | Sim | Encomendas |

Observações:

- Um cliente pode fazer várias encomendas
- Cada encomenda pertence a um e um só cliente

#### **Sec 6.2.4: Associa**

Este relacionamento diz-nos que encomendas contém cada entrega.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Entrega | Sim | 1:1 | Não | Encomendas |

Observações:

- Uma entrega contém obrigatóriamente uma encomenda
- Uma encomenda será parte de uma entrega

#### **Sec 6.2.5: Escolha**

Este relacionamento diz-nos que encomendas são entregues por cada um dos estafetas.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Encomendas | Sim | N:1 | Não | Estafetas |

Observações:

- Qualquer encomenda pode ser escolhida por um estafeta
- Cada estafeta pode escolher uma ou mais encomendas

#### **Sec 6.2.6: Paga Usando**

Este relacionamento diz-nos qual o método de pagamento usado para cada encomenda feita.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Encomendas | Sim | N:1 | Não | Método Pagamento |

Observações:

- Cada encomenda contém um único método de pagamento
- Cada método de pagamento pode ser usado para várias encomendas

#### **Sec 6.2.7: Pagamento Comissões**

Este relacionamento diz-nos qual o método de pagamento usado para cada encomenda feita.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Pagamento | Sim | N:1 | Não | Estafeta |

Observações:

- Cada estafeta pode receber um ou mais pagamentos de comissões
- Cada pagamento é feito a um só estafeta

#### **Sec 6.2.8: Entregue por**

Este relacionamento diz-nos qual o método de pagamento usado para cada encomenda feita.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Entrega | Sim | N:1 | Não | Estafeta |

Observações:

- Cada estafeta pode ter uma ou mais entregas
- Cada entrega só pode ser realizada por um estafeta

#### **Sec 6.2.9: Conduz**

Este relacionamento diz-nos que veículo é conduzido por cada um dos estafetas.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Estafeta | Não | 1:1 | Não | Veículo |

Observações:

- Um estafeta pode conduzir um veículo
- Cada veículo é conduzido por um estafeta

#### **Sec 6.2.10: Têm Determinada**

Este relacionamento diz-nos a marca de cada produto.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Produtos | Sim | N:1 | Sim | Marca |

Observações:

- Cada produto tem uma e uma só marca
- Cada marca tem vários produtos

#### **Sec 6.2.11: Vendida Em**

Este relacionamento diz-nos a marca de cada produto.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Produtos | Sim | M:N | Sim | Marca |

Observações:

- Cada produto tem uma e uma só marca
- Cada marca tem vários produtos

#### **Sec 6.2.12: Vende**

Este relacionamento indica-nos quais os locais de entrega dos clientes.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Produtos | Sim | 1:N | Sim | Lojas |

Observações:

- Cada produto tem uma e uma só marca
- Cada marca tem vários produtos

#### **Sec 6.2.13: Pertence a**

Este relacionamento indica-nos quais as vendas de produtos realizadas em cada loja.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Locais de Entrega | Sim | M:N | Não | Cliente |

Observações:

- Cada local de entrega pertence a um ou mais clientes
- Cada cliente tem um ou mais locais de entrega

| Nome do Atributo | Aceita Nulos? | Valores Únicos? | Observações |
| --- | --- | --- | --- |
| Nome | Não | Não | Locais de entrega diferentes podem ter o mesmo nome |

#### **Sec 6.2.14: Contêm**

Este relacionamento indica-nos quais os produtos contidos nas várias encomendas.

| Entidade | Obrigatório | Cardinalidade | Obrigatório | Entidade |
| --- | --- | --- | --- | --- |
| Encomendas | Sim | M:N | Não | Produtos |

Observações:

- Cada encomenda tem um ou mais produtos
- Cada produto pertence a uma ou mais encomendas

Atributos relevantes do relacionamento:

| Nome do Atributo | Aceita Nulos? | Valores Únicos? | Observações |
| --- | --- | --- | --- |
| Quantidade | Não | Não | Produtos diferentes podem ter a mesma quantidade |
| Preço Atual | Não | Não | Produtos diferentes podem ter o mesmo preço atual |

### **Sec 6.3: Diagrama do Modelo Conceptual**

O modelo de Entidade Relacionamento completo é o que consta em baixo. Aqui o traço nas linhas que levam a relacionamentos segue uma notação contrário à do retângulo regularmente usado nas aulas.

![Conceptual_PowerDesigner](https://i.imgur.com/DPWbLqt.png)

---

## **Cap 7: Modelo Físico**

### **Sec 7.1: Tabelas**

Nesta secção são descritas as tabelas necessárias para implementar o negócio de entrega de produtos. Estas tabelas foram extraídas, tomando em consideração o modelo Entidade / Relacionamento definido no capítulo 6. As tabelas são as seguintes:

- Locais de Entrega
- Cliente
- Estafeta
- Pagamento
- Veículo
- Encomendas
- Estados
- Entrega
- Métodos de Pagamento
- Produtos
- Marcas
- Lojas
- Pertence a
- Escolha
- Conduz
- Contêm
- Vendida em

#### **Sec 7.1.1: Tabela Locais de Entrega**

A tabela Locais de Entrega vai conter a informação sobre os locais de entrega inseridos por clientes. Sempre que um cliente pretenda adicionar um local de entrega, é adicionado um novo registo à tabela.

Restrições da tabela Locais de Entrega:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial |
| --- | --- | --- | --- |
| ID_Local | NUMBER(8) | PK_LOCAIS | PRIMARY KEY |
| Rua | VARCHAR2(200) | NN_LOCAIS_RUA | NOT NULL |
| Numero_Porta | NUMBER(4) | NN_LOCAIS_NPORTA | NOT NULL |
| Numero_Porta | NUMBER(4) | CK_LOCAIS_POS_NPORTA | CHECK (Numero_Porta BETWEEN 0 AND 9999) |
| Andar | NUMBER(2) | CK_LOCAIS_POS_ANDAR | CHECK (Andar BETWEEN 0 AND 99) |
| Codigo_Postal | NUMBER(7) | NN_LOCAIS_CODPOST | NOT NULL |
| Codigo_Postal | NUMBER(7) | CK_LOCAIS_CODPOST | CHECK (Codigo_Postal BETWEEN 0 AND 9999999) |

#### **Sec 7.1.2: Tabela Cliente**

A tabela Cliente vai conter a informação sobre os clientes registados no sistema. Sempre que ocorre um registo de um cliente, é adicionado um novo registo à tabela.

Restrições da tabela Cliente:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial |
| --- | --- | --- | --- |
| ID_Cliente | NUMBER(8) |  PK_CLIENTE | PRIMARY KEY |
| Nome | VARCHAR2(50) | NN_CLI_NOME | NOT NULL |
| Data_Nascimento | DATE | NN_CLI_DATA_NASC | NOT NULL |

#### **Sec 7.1.3: Tabela Estafeta**

A tabela Estafeta vai conter a informação sobre os clientes registados no sistema. Sempre que ocorre um registo de um cliente, é adicionado um novo registo à tabela.

Restrições da tabela Estafeta:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Estafeta | NUMBER(8) | PK_ESTAFETA | PRIMARY KEY |
| Nome | VARCHAR2(50) | NN_EST_NOME | NOT NULL |
| Data_Nascimento | DATE | NN_EST_DATA_NASC | NOT NULL |
| Telemóvel | NUMBER(9) | NN_EST_TEL | NOT NULL |
| Telemóvel | NUMBER(9) | UK_EST_TEL | UNIQUE |
| Email | VARCHAR2(50) | NN_EST_EMAIL | NOT NULL |
| Email | VARCHAR2(50) | UK_EST_EMAIL | UNIQUE |
| Posição | VARCHAR2(50) | NN_EST_POS | NOT NULL |
| Comissão_Por_Pagar | NUMBER(8,2) | NN_COMISS_EST | NOT NULL |
| Comissão_Por_Pagar | NUMBER(8,2) | CK_EST_POS_COMISS | CHECK (COMISSÃO_POR_PAGAR BETWEEN 0 AND 999999) |
| Foto_URL | VARCHAR2(100) | NN_EST_FOTO | NOT NULL |
| Foto_URL | VARCHAR2(100) | UK_EST_FOTO | UNIQUE |

#### **Sec 7.1.4: Tabela Pagamento**
A tabela Pagamento vai conter a informação sobre os pagamentos feitos a estafetas. Sempre que é efetuado um pagamento, é adicionado um novo registo à tabela.

Restrições da tabela Pagamento:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Pagamento | NUMBER(8) | PK_PAGAMENTO | PRIMARY KEY |
| ID_Estafeta | NUMBER(8) | FK_PAGAMENT_PAGAMENTO_ESTAFETA | FOREIGN KEY REFERENCES ESTAFETA (ID_Estafeta) | 
| Montante | NUMBER(6,2) | NN_PAG_MONTANTE | NOT NULL |
| Montante | NUMBER(6,2) | CK_PAG_MONTANTE | CHECK (MONTANTE BETWEEN 0 AND 9999) |
| Data_Pagamento | DATE | NN_PAG_DATA | NOT NULL |

#### **Sec 7.1.5: Tabela Veículo**

A tabela Veículo vai conter a informação sobre os veículos da empresa. Sempre que a empresa adquire um novo veículo, é adicionado um novo registo à tabela.

Restrições da tabela Veículo:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| Matrícula | VARCHAR2(10) | PK_VEICULO | PRIMARY KEY |
| Disponibilidade | SMALLINT | NN_VEIC_DISP | NOT NULL | 
| Modelo | VARCHAR2(20) | NN_VEIC_MODELO | NOT NULL |
| Marca | VARCHAR2(20) | NN_VEIC_MARCA | NOT NULL |

#### **Sec 7.1.6: Tabela Encomendas**

A tabela Encomendas vai conter a informação sobre as encomendas feitas por clientes. Sempre que um cliente faz uma encomenda, é adicionado um novo registo à tabela.

Restrições da tabela Encomendas:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Encomenda | NUMBER(8) | PK_ENCOMENDA | PRIMARY KEY |
| ID_Local | NUMBER(8) | FK_ENCOMEND_ENTREGUE__LOCAIS_D | FOREIGN KEY REFERENCES LOCAIS_DE_ENTREGA (ID_Estafeta) |
| ID_Cliente | NUMBER(8) | FK_ENCOMEND_FEITA_POR_CLIENTE | FOREIGN KEY REFERENCES CLIENTE (ID_Cliente) |
| ID_Estado | NUMBER(8) | FK_ENCOMEND_ENCONTRA__ESTADOS | FOREIGN KEY REFERENCES ESTADO (ID_Estado) |
| Nome_Método | VARCHAR2(50) | FK_ENCOMEND_PAGA_USAN_METODOS | FOREIGN KEY REFERENCES METODOS_PAGAMENTO (Nome_Metodo) |
| Taxa_Entrega | NUMBER(8,2) | NN_ENC_TAX | NOT NULL |
| Taxa_Entrega | NUMBER(8,2) | CK_POS_ENC_TAX | CHECK (TAXA_ENTREGA BETWEEN 0 AND 9999) |
| Data_Encomenda | DATE | NN_ENC_DATENC | NOT NULL |
| Data_Entrega_Desejada | DATE | NN_ENC_DATENTDES | NOT NULL |

#### **Sec 7.1.7: Tabela Estados**

A tabela Estados vai conter a informação sobre o estados possíveis de uma encomenda. Sempre que seja necessário adicionar um estado que até então não existia, é adicionado um novo registo à tabela.

Restrições da tabela Estados:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Estado | NUMBER(8) | PK_ESTADO | PRIMARY KEY |
| Nome_Estado | VARCHAR2(20) | NN_NOME_ESTADO | NOT NULL |

#### **Sec 7.1.8: Tabela Entrega**

A tabela Entrega vai conter a informação sobre as entregas efetuadas pelos estafetas. Ao ser finalizada uma entrega pelo estafeta, é adicionado um novo registo à tabela.

Restrições da tabela Entrega:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Entrega | NUMBER(8) | PK_ENTREGA | PRIMARY KEY |
| ID_Encomenda | NUMBER(8) | FK_ENTREGA_ASSOCIA_ENCOMEND | FOREIGN KEY REFERENCES ENCOMENDAS (ID_Encomenda) |
| ID_Estafeta | NUMBER(8) | FK_ENTREGA_ENTREGUE__ESTAFETA | FOREIGN KEY REFERENCES ESTAFETA (ID_Estafeta) |
| Data_Entrega | DATE | NN_ENT_DATA | NOT NULL |
| Rating | NUMBER(2) | CK_VALID_ENT_RAT | CHECK (Rating BETWEEN 0 AND 10) |

#### **Sec 7.1.9: Tabela Métodos de Pagamento**

A tabela Métodos de Pagamento vai conter a informação sobre todos os métodos de pagamento possíveis. Caso se queira incluir um novo método de pagamento, deve ser adicionado um registo à tabela.

Restrições à tabela Métodos de Pagamento:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| Nome_Método | VARCHAR2(50) | PK_METPAG | PRIMARY KEY |

#### **Sec 7.1.10: Tabela Produtos**

A tabela Produtos vai conter a informação sobre todos os produtos vendidos pelas lojas. Sempre que uma loja queira adicionar um novo produto, é adicionado um novo registo à tabela.

Restrições à tabela Produtos:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Produto | NUMBER(8) | PK_PRODUTOS | PRIMARY KEY |
| ID_Loja | NUMBER(8) | FK_PRODUTOS_VENDE_LOJAS | FOREIGN KEY REFERENCES LOJAS (ID_Loja) |
| ID_Marca | NUMBER(8) | FK_PRODUTOS_TEM_DETER_MARCAS | FOREIGN KEY REFERENCES MARCAS (ID_Marca) |
| Preco_Tabela | NUMBER(8,2) | NN_PROD_PREC | NOT NULL |
| Preco_Tabela | NUMBER(8,2) | CK_POS_PROD_PREC | CHECK (PRECO_TABELA BETWEEN 0 AND 999999) |
| Nome_Produto | VARCHAR2(30) | NN_PROD_NOME | NOT NULL |

#### **Sec 7.1.11: Tabela Marcas**

A tabela Marcas vai conter a informação sobre todas as marcas existentes no sistema. Sempre que uma loja queira adicionar uma marca que ainda não exista na tabela, é adicionado um novo registo.

Restrições à tabela Marcas:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Marca | NUMBER(8) | PK_MARCAS | PRIMARY KEY |
| Nome_Marca | VARCHAR2(30) | NN_MARCA_NOME | NOT NULL |
| Nome_Marca | VARCHAR2(30) | UK_MARCA_NOME | UNIQUE |

#### **Sec 7.1.12: Tabela Lojas**

A tabela Lojas vai conter a informação sobre as lojas abrangidas pelo sistema de entregas. Sempre que uma loja se associe ao sistema, é adicionado um novo registo à tabela.

Restrições à tabela Lojas:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Loja | NUMBER(8) | PK_LOJAS | PRIMARY KEY |
| Localização | VARCHAR2(200) | NN_LOJA_LOCAL | NOT NULL |
| Nome_Loja | VARCHAR2(30) | NN_LOJA_NOME | NOT NULL 

#### **Sec 7.1.13: Tabela Pertence a**

A tabela Pertence a vai relacionar as tabelas Locais de Entrega e Cliente. Sempre que o Cliente adicione um local de entrega, é guardado o seu nome e referências às tabelas correspondentes.

Restrições à tabela Pertence a:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Cliente + ID_Local | NUMBER(8) | PK_LOJAS | PRIMARY KEY |
| ID_Local | NUMBER(8) | FK_PERTENCE_LOCAL_PER_LOCAIS_D | FOREIGN KEY REFERENCES LOCAIS_DE_ENTREGA (ID_Estafeta) |
| ID_Cliente | NUMBER(8) | FK_PERTENCE_REFERE_CL_CLIENTE | FOREIGN KEY REFERENCES CLIENTE (ID_Cliente) |
| Nome | VARCHAR2(50) | NN_PRTC_NOME | NOT NULL |

#### **Sec 7.1.14: Tabela Escolha**

A tabela Escolha vai relacionar as tabelas Estafeta e Encomenda. Sempre que o Estafeta faça uma escolha entre as encomendas disponíveis para ser entregues, é criado um novo registo nesta tabela.

Restrições à tabela Escolha:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Encomenda + ID_Estafeta | NUMBER(8) | PK_ESCOLHA | PRIMARY KEY |
| ID_Encomenda | NUMBER(8) | FK_ESCOLHA_REFERENCE_ENCOMEND | FOREIGN KEY REFERENCES ENCOMENDAS (ID_Encomenda) |
| ID_Estafeta | NUMBER(8) | FK_ESCOLHA_REFERENCE_ESTAFETA | FOREIGN KEY REFERENCES ESTAFETA (ID_Estafeta) |

#### **Sec 7.1.15: Tabela Conduz**

A tabela Conduz vai relacionar as tabelas Estafeta e Veículo. Quando o estafeta se regista no sistema, é-lhe atribuído um veículo e é criado um novo registo nesta tabela.

Restrições à tabela Conduz:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Estafeta + Matrícula | NUMBER(8) + VARCHAR2(10) | PK_CONDUZ | PRIMARY KEY |
| ID_Estafeta | NUMBER(8) | FK_CONDUZ_REFERENCE_ESTAFETA | FOREIGN KEY REFERENCES ESTAFETA (ID_Estafeta) |
| Matricula | VARCHAR2(20) | FK_CONDUZ_REFERENCE_VEICULO | FOREIGN KEY REFERENCES VEICULO (Matricula) |

#### **Sec 7.1.16: Tabela Contêm**

A tabela Contêm vai relacionar as tabelas Encomenda e Produto. Sempre que um cliente faz uma encomenda, os diferentes produtos encomendados, assim como a sua quantidade e preço, são registados nesta tabela.

Restrições à tabela Contêm:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Encomenda + ID_Produto | NUMBER(8) | PK_CONTEM | PRIMARY KEY |
| ID_Encomenda | NUMBER(8) | FK_CONTEM_ENCOMENDA_ENCOMEND | FOREIGN KEY REFERENCES ENCOMENDAS (ID_Encomenda) |
| ID_Produto | NUMBER(8) | FK_CONTEM_REFERE_PR_PRODUTOS | FOREIGN KEY REFERENCES PRODUTOS (ID_Produto) |
| Quantidade | NUMBER(8) | NN_CONT_QUANT | NOT NULL |
| Quantidade | NUMBER(8) | CK_POS_CONT_QUANTO | CHECK (Quantidade > 0)
| Preco_Atual | NUMBER(8,2) | NN_CONT_PRECO | NOT NULL |
| Preco_Atual | NUMBER(8,2) | CK_POS_CONT_PRECO | CHECK (Preco_Atual BETWEEN 0 AND 999999) |

#### **Sec 7.1.17: Tabela Vendida em**

A tabela Vendida em vai relacionar as tabelas Marca e Lojas e contem a informação sobre quais lojas vendem quais marcas. Sempre que uma loja queira adicionar uma marca vendida, é adicionado um novo registo à tabela.

Restrições à tabela Vendida em:

| Atributo(s) | Tipo de Dados | Nome da Restrição | Restrições de Integridade Referencial
| --- | --- | --- | --- |
| ID_Marca + ID_Loja | NUMBER(8) | PK_VENDIDAEM | PRIMARY KEY |
| ID_Loja | NUMBER(8) | FK_VENDIDA__VENDIDA_E_LOJAS | FOREIGN KEY REFERENCES LOJAS (ID_Loja) |
| ID_Marca | NUMBER(8) | FK_VENDIDA__VENDIDA_E_MARCAS | FOREIGN KEY REFERENCES MARCAS (ID_Marca) |

### **Sec 7.2: Diagrama do Modelo Físico**

O modelo Físico (ou diagrama de tabelas) completo com todas as tabelas, realizado em PowerDesigner, é o seguinte.

![Fisico_PowerDesigner](https://i.imgur.com/QcAA9ln.png)

### **Sec 7.3: Script de criação da Base de Dados**

```SQL

/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     16-Jan-21 04:42:02                           */
/*==============================================================*/


alter table CONDUZ
   drop constraint FK_CONDUZ_REFERENCE_ESTAFETA;

alter table CONDUZ
   drop constraint FK_CONDUZ_REFERENCE_VEICULO;

alter table CONTEM
   drop constraint FK_CONTEM_ENCOMENDA_ENCOMEND;

alter table CONTEM
   drop constraint FK_CONTEM_REFERE_PR_PRODUTOS;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_ENCONTRA__ESTADOS;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_ENTREGUE__LOCAIS_D;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_FEITA_POR_CLIENTE;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_PAGA_USAN_METODOS;

alter table ENTREGA
   drop constraint FK_ENTREGA_ASSOCIA_ENCOMEND;

alter table ENTREGA
   drop constraint FK_ENTREGA_ENTREGUE__ESTAFETA;

alter table ESCOLHA
   drop constraint FK_ESCOLHA_REFERENCE_ENCOMEND;

alter table ESCOLHA
   drop constraint FK_ESCOLHA_REFERENCE_ESTAFETA;

alter table PAGAMENTO
   drop constraint FK_PAGAMENT_PAGAMENTO_ESTAFETA;

alter table PERTENCE_A
   drop constraint FK_PERTENCE_LOCAL_PER_LOCAIS_D;

alter table PERTENCE_A
   drop constraint FK_PERTENCE_REFERE_CL_CLIENTE;

alter table PRODUTOS
   drop constraint FK_PRODUTOS_TEM_DETER_MARCAS;

alter table PRODUTOS
   drop constraint FK_PRODUTOS_VENDE_LOJAS;

alter table VENDIDA_EM
   drop constraint FK_VENDIDA__VENDIDA_E_MARCAS;

alter table VENDIDA_EM
   drop constraint FK_VENDIDA__VENDIDA_E_LOJAS;

drop table CLIENTE cascade constraints;

drop table CONDUZ cascade constraints;

drop index REFERE_FK;

drop index TEM_FK;

drop table CONTEM cascade constraints;

drop index ENCONTRA_SE_FK;

drop index PAGA_USANDO_FK;

drop index FEITA_POR_FK;

drop index ENTREGUE_EM_FK;

drop table ENCOMENDAS cascade constraints;

drop index ENTREGUE_POR_FK;

drop table ENTREGA cascade constraints;

drop table ESCOLHA cascade constraints;

drop table ESTADOS cascade constraints;

drop table ESTAFETA cascade constraints;

drop table LOCAIS_DE_ENTREGA cascade constraints;

drop table LOJAS cascade constraints;

drop table MARCAS cascade constraints;

drop table METODOS_PAGAMENTO cascade constraints;

drop index PAGAMENTO_COMISSOES_FK;

drop table PAGAMENTO cascade constraints;

drop index PERTENCE_A2_FK;

drop index PERTENCE_A_FK;

drop table PERTENCE_A cascade constraints;

drop index VENDE_FK;

drop index TEM_DETERMINADA_FK;

drop table PRODUTOS cascade constraints;

drop table VEICULO cascade constraints;

drop index VENDIDA_EM2_FK;

drop index VENDIDA_EM_FK;

drop table VENDIDA_EM cascade constraints;

/*==============================================================*/
/* Table: CLIENTE                                               */
/*==============================================================*/
create table CLIENTE 
(
   ID_CLIENTE           NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         constraint NN_CLI_NOME not null,
   DATA_NASCIMENTO      DATE                 constraint NN_CLI_DATA_NASC not null,
   TELEMOVEL            NUMBER(9),
   EMAIL                VARCHAR2(50),
   FOTO_URL             VARCHAR2(100),
   constraint PK_CLIENTE primary key (ID_CLIENTE)
);

/*==============================================================*/
/* Table: CONDUZ                                                */
/*==============================================================*/
create table CONDUZ 
(
   ID_ESTAFETA          NUMBER(8)            not null,
   MATRICULA            VARCHAR2(10)       not null,
   constraint PK_CONDUZ primary key (ID_ESTAFETA, MATRICULA)
);

/*==============================================================*/
/* Table: CONTEM                                                */
/*==============================================================*/
create table CONTEM 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_PRODUTO           NUMBER(8)            not null,
   QUANTIDADE           NUMBER(8)            constraint NN_CONT_QUANT not null constraint CK_POS_CONT_QUANTO CHECK (QUANTIDADE > 0),
   PRECO_ATUAL          NUMBER(8,2)          constraint NN_CONT_PRECO not null constraint CK_POS_CONT_PRECO CHECK (PRECO_ATUAL between 0 and 999999),
   constraint PK_CONTEM primary key (ID_ENCOMENDA, ID_PRODUTO)
);

/*==============================================================*/
/* Index: TEM_FK                                                */
/*==============================================================*/
create index TEM_FK on CONTEM (
   ID_ENCOMENDA ASC
);

/*==============================================================*/
/* Index: REFERE_FK                                             */
/*==============================================================*/
create index REFERE_FK on CONTEM (
   ID_PRODUTO ASC
);

/*==============================================================*/
/* Table: ENCOMENDAS                                            */
/*==============================================================*/
create table ENCOMENDAS 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_LOCAL             NUMBER(8)            not null,
   ID_CLIENTE           NUMBER(8)            not null,
   ID_ESTADO            NUMBER(8)            not null,
   NOME_METODO          VARCHAR2(50)         not null,
   TAXA_ENTREGA         NUMBER(8,2)          constraint NN_ENC_TAX not null constraint CK_POS_ENC_TAX check (TAXA_ENTREGA between 0 and 9999),
   DATA_ENCOMENDA       DATE                 constraint NN_ENC_DATENC not null,
   NIF                  NUMBER(9),
   DATA_ENTREGA_DESEJADA DATE                constraint NN_ENC_DATENTDES not null,
   constraint PK_ENCOMENDAS primary key (ID_ENCOMENDA)
);

/*==============================================================*/
/* Index: ENTREGUE_EM_FK                                        */
/*==============================================================*/
create index ENTREGUE_EM_FK on ENCOMENDAS (
   ID_LOCAL ASC
);

/*==============================================================*/
/* Index: FEITA_POR_FK                                          */
/*==============================================================*/
create index FEITA_POR_FK on ENCOMENDAS (
   ID_CLIENTE ASC
);

/*==============================================================*/
/* Index: PAGA_USANDO_FK                                        */
/*==============================================================*/
create index PAGA_USANDO_FK on ENCOMENDAS (
   NOME_METODO ASC
);

/*==============================================================*/
/* Index: ENCONTRA_SE_FK                                        */
/*==============================================================*/
create index ENCONTRA_SE_FK on ENCOMENDAS (
   ID_ESTADO ASC
);

/*==============================================================*/
/* Table: ENTREGA                                               */
/*==============================================================*/
create table ENTREGA 
(
   ID_ENTREGA           NUMBER(8)            not null,
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   DATA_ENTREGA         DATE                 constraint NN_ENT_DATA not null,
   RATING               NUMBER(3,1)          constraint CK_VALID_ENT_RAT check (RATING between 0 and 10),
   constraint PK_ENTREGA primary key (ID_ENTREGA)
);

/*==============================================================*/
/* Index: ENTREGUE_POR_FK                                       */
/*==============================================================*/
create index ENTREGUE_POR_FK on ENTREGA (
   ID_ESTAFETA ASC
);

/*==============================================================*/
/* Table: ESCOLHA                                               */
/*==============================================================*/
create table ESCOLHA 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   constraint PK_ESCOLHA primary key (ID_ENCOMENDA, ID_ESTAFETA)
);

/*==============================================================*/
/* Table: ESTADOS                                               */
/*==============================================================*/
create table ESTADOS 
(
   ID_ESTADO            NUMBER(8)            not null,
   NOME_ESTADO          VARCHAR2(30)         constraint NN_NOME_ESTADO not null,
   constraint PK_ESTADOS primary key (ID_ESTADO)
);

/*==============================================================*/
/* Table: ESTAFETA                                              */
/*==============================================================*/
create table ESTAFETA 
(
   ID_ESTAFETA          NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         constraint NN_EST_NOME not null,
   DATA_NASCIMENTO      DATE                 constraint NN_EST_DATA_NASC not null,
   TELEMOVEL            NUMBER(9)            constraint NN_EST_TEL not null constraint UK_EST_TEL unique,
   EMAIL                VARCHAR2(50)         constraint NN_EST_EMAIL not null constraint UK_EST_EMAIL unique,
   POSICAO              VARCHAR2(50)         constraint NN_EST_POS not null,
   COMISSAO_POR_PAGAR   NUMBER(8,2)          constraint NN_COMISS_EST not null constraint CK_EST_POS_COMISS check (COMISSAO_POR_PAGAR between 0 and 999999),
   FOTO_URL             VARCHAR2(100)        constraint NN_EST_FOTO not null constraint UK_EST_FOTO unique,
   constraint PK_ESTAFETA primary key (ID_ESTAFETA)
);

/*==============================================================*/
/* Table: LOCAIS_DE_ENTREGA                                     */
/*==============================================================*/
create table LOCAIS_DE_ENTREGA 
(
   ID_LOCAL             NUMBER(8)            not null,
   RUA                  VARCHAR2(200)        not null,
   NUMERO_PORTA         NUMBER(4)            constraint NN_LOCAIS_NPORTA not null constraint CK_LOCAIS_POS_NPORTA check (Numero_Porta between 0 and 9999),
   ANDAR                NUMBER(2)            constraint CK_LOCAIS_POS_ANDAR check (ANDAR between 0 and 99),
   CODIGO_POSTAL        NUMBER(7)            constraint NN_LOCAIS_CODPOST not null constraint CK_LOCAIS_CODPOST check (CODIGO_POSTAL between 0 and 9999999),
   CIDADE               VARCHAR2(50),
   constraint PK_LOCAIS_DE_ENTREGA primary key (ID_LOCAL)
);

/*==============================================================*/
/* Table: LOJAS                                                 */
/*==============================================================*/
create table LOJAS 
(
   ID_LOJA              NUMBER(8)            constraint AUTBAK_NL_NULL not null,
   TIPO_LOJA            VARCHAR2(30),
   LOCALIZACAO          VARCHAR2(200)        constraint NN_LOJA_LOCAL not null,
   NOME_LOJA            VARCHAR2(30)         constraint NN_LOJA_NOME not null,
   constraint PK_LOJAS primary key (ID_LOJA)
);

/*==============================================================*/
/* Table: MARCAS                                                */
/*==============================================================*/
create table MARCAS 
(
   ID_MARCA             NUMBER(8)            not null,
   NOME_MARCA           VARCHAR2(30)         constraint NN_MARCA_NOME not null constraint UK_MARCA_NOME unique,
   constraint PK_MARCAS primary key (ID_MARCA)
);

/*==============================================================*/
/* Table: METODOS_PAGAMENTO                                     */
/*==============================================================*/
create table METODOS_PAGAMENTO 
(
   NOME_METODO          VARCHAR2(50)         not null,
   constraint PK_METODOS_PAGAMENTO primary key (NOME_METODO)
);

/*==============================================================*/
/* Table: PAGAMENTO                                             */
/*==============================================================*/
create table PAGAMENTO 
(
   ID_PAGAMENTO         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   MONTANTE             NUMBER(8,2)          constraint NN_PAG_MONTANTE not null constraint CK_PAG_MONTANTE check (MONTANTE between 0 and 9999),
   DATA_PAGAMENTO       DATE                 not null,
   constraint PK_PAGAMENTO primary key (ID_PAGAMENTO)
);

/*==============================================================*/
/* Index: PAGAMENTO_COMISSOES_FK                                */
/*==============================================================*/
create index PAGAMENTO_COMISSOES_FK on PAGAMENTO (
   ID_ESTAFETA ASC
);

/*==============================================================*/
/* Table: PERTENCE_A                                            */
/*==============================================================*/
create table PERTENCE_A 
(
   ID_CLIENTE           NUMBER(8)            not null,
   ID_LOCAL             NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         constraint NN_PRTC_NOME not null,
   constraint PK_PERTENCE_A primary key (ID_CLIENTE, ID_LOCAL)
);

/*==============================================================*/
/* Index: PERTENCE_A_FK                                         */
/*==============================================================*/
create index PERTENCE_A_FK on PERTENCE_A (
   ID_CLIENTE ASC
);

/*==============================================================*/
/* Index: PERTENCE_A2_FK                                        */
/*==============================================================*/
create index PERTENCE_A2_FK on PERTENCE_A (
   ID_LOCAL ASC
);

/*==============================================================*/
/* Table: PRODUTOS                                              */
/*==============================================================*/
create table PRODUTOS 
(
   ID_PRODUTO           NUMBER(8)            not null,
   ID_LOJA              NUMBER(8)            not null,
   ID_MARCA             NUMBER(8)            not null,
   PRECO_TABELA         NUMBER(8,2)          constraint NN_PROD_PREC not null constraint CK_POS_PROD_PREC check (PRECO_TABELA between 0 and 999999),
   NOME_PRODUTO         VARCHAR2(30)         constraint NN_PROD_NOME not null,
   constraint PK_PRODUTOS primary key (ID_PRODUTO)
);

/*==============================================================*/
/* Index: TEM_DETERMINADA_FK                                    */
/*==============================================================*/
create index TEM_DETERMINADA_FK on PRODUTOS (
   ID_MARCA ASC
);

/*==============================================================*/
/* Index: VENDE_FK                                              */
/*==============================================================*/
create index VENDE_FK on PRODUTOS (
   ID_LOJA ASC
);

/*==============================================================*/
/* Table: VEICULO                                               */
/*==============================================================*/
create table VEICULO 
(
   MATRICULA            VARCHAR2(10)         not null,
   TIPO_VEICULO         VARCHAR2(20),
   DISPONIBILIDADE      SMALLINT             constraint NN_VEIC_DISP not null,
   MODELO               VARCHAR2(20)         constraint NN_VEIC_MODELO not null,
   MARCA                VARCHAR2(20)         constraint NN_VEIC_MARCA not null,
   constraint PK_VEICULO primary key (MATRICULA)
);

/*==============================================================*/
/* Table: VENDIDA_EM                                            */
/*==============================================================*/
create table VENDIDA_EM 
(
   ID_MARCA             NUMBER(8)            not null,
   ID_LOJA              NUMBER(8)            not null,
   constraint PK_VENDIDAEM primary key (ID_MARCA, ID_LOJA)
);

/*==============================================================*/
/* Index: VENDIDA_EM_FK                                         */
/*==============================================================*/
create index VENDIDA_EM_FK on VENDIDA_EM (
   ID_MARCA ASC
);

/*==============================================================*/
/* Index: VENDIDA_EM2_FK                                        */
/*==============================================================*/
create index VENDIDA_EM2_FK on VENDIDA_EM (
   ID_LOJA ASC
);

alter table CONDUZ
   add constraint FK_CONDUZ_REFERENCE_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table CONDUZ
   add constraint FK_CONDUZ_REFERENCE_VEICULO foreign key (MATRICULA)
      references VEICULO (MATRICULA);

alter table CONTEM
   add constraint FK_CONTEM_ENCOMENDA_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table CONTEM
   add constraint FK_CONTEM_REFERE_PR_PRODUTOS foreign key (ID_PRODUTO)
      references PRODUTOS (ID_PRODUTO);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_ENCONTRA__ESTADOS foreign key (ID_ESTADO)
      references ESTADOS (ID_ESTADO);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_ENTREGUE__LOCAIS_D foreign key (ID_LOCAL)
      references LOCAIS_DE_ENTREGA (ID_LOCAL);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_FEITA_POR_CLIENTE foreign key (ID_CLIENTE)
      references CLIENTE (ID_CLIENTE);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_PAGA_USAN_METODOS foreign key (NOME_METODO)
      references METODOS_PAGAMENTO (NOME_METODO);

alter table ENTREGA
   add constraint FK_ENTREGA_ASSOCIA_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table ENTREGA
   add constraint FK_ENTREGA_ENTREGUE__ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table ESCOLHA
   add constraint FK_ESCOLHA_REFERENCE_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table ESCOLHA
   add constraint FK_ESCOLHA_REFERENCE_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table PAGAMENTO
   add constraint FK_PAGAMENT_PAGAMENTO_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table PERTENCE_A
   add constraint FK_PERTENCE_LOCAL_PER_LOCAIS_D foreign key (ID_LOCAL)
      references LOCAIS_DE_ENTREGA (ID_LOCAL);

alter table PERTENCE_A
   add constraint FK_PERTENCE_REFERE_CL_CLIENTE foreign key (ID_CLIENTE)
      references CLIENTE (ID_CLIENTE);

alter table PRODUTOS
   add constraint FK_PRODUTOS_TEM_DETER_MARCAS foreign key (ID_MARCA)
      references MARCAS (ID_MARCA);

alter table PRODUTOS
   add constraint FK_PRODUTOS_VENDE_LOJAS foreign key (ID_LOJA)
      references LOJAS (ID_LOJA);

alter table VENDIDA_EM
   add constraint FK_VENDIDA__VENDIDA_E_MARCAS foreign key (ID_MARCA)
      references MARCAS (ID_MARCA);

alter table VENDIDA_EM
   add constraint FK_VENDIDA__VENDIDA_E_LOJAS foreign key (ID_LOJA)
      references LOJAS (ID_LOJA);
```

## **Cap 8: Pesquisas SQL**

**Q1**: Veículos existentes para serem utilizados pelos estafetas.

```sql
select MATRICULA, MARCA || ' ' || MODELO as MODELO, case when DISPONIBILIDADE = 1 then 'SIM' when DISPONIBILIDADE = 0 then 'NAO' else 'ERROR' end as DISP
from VEICULO
order by 3 desc;
```

Ecrã de veículos admin.

**Q2**: Lista de clientes, os seus locais de entrega e número de encomendas realizadas.

```sql
select CLI.ID_CLIENTE as ID, CLI.NOME, count(LOCAIS.ID_LOCAL) as "N Locais Ent", count(ENC.ID_ENCOMENDA) as "N. Encom."
from CLIENTE CLI, LOCAIS_DE_ENTREGA LOCAIS, ENCOMENDAS ENC
where ENC.ID_CLIENTE = CLI.ID_CLIENTE
and LOCAIS.ID_LOCAL = ENC.ID_LOCAL 
group by CLI.ID_CLIENTE, CLI.NOME
order by 4 desc;
```

Ecrã de clientes admin.

**Q3**: Lista os produtos disponíveis a serem encomendados.

```sql
select L.NOME_LOJA, PROD.NOME_PRODUTO, PROD.PRECO_TABELA
from PRODUTOS PROD, LOJAS L
where PROD.ID_LOJA = L.ID_LOJA
and upper(PROD.NOME_PRODUTO) like '%BACALHAU%';
```

Ecrã de pesquisa do cliente.

**Q4**: Lista as encomendas sem estafeta associado

```sql
select L.NOME_LOJA, PROD.NOME_PRODUTO, CONT.QUANTIDADE, ENC.TAXA_ENTREGA
from LOJAS L, PRODUTOS PROD, CONTEM CONT, ENCOMENDAS ENC
where ENC.ID_ENCOMENDA = CONT.ID_ENCOMENDA
and CONT.ID_PRODUTO = PROD.ID_PRODUTO
and PROD.ID_LOJA = L.ID_LOJA
and not exists (select ESC.ID_ENCOMENDA
               from ESCOLHA ESC
               where ENC.ID_ENCOMENDA = ESC.ID_ENCOMENDA);
```

Ecrã home do estafeta.

**Q5**: Lista as encomendas realizadas pelo cliente

```sql
select ENC.DATA_ENCOMENDA, EST.NOME_ESTADO, sum(TTL.TOTAL)
from ENCOMENDAS ENC, ESTADOS EST, (select PRECO_ATUAL * QUANTIDADE as TOTAL, ID_ENCOMENDA as IDTTL from CONTEM) TTL
where ENC.ID_ESTADO = EST.ID_ESTADO
and ENC.ID_ENCOMENDA = TTL.IDTTL
order by 1 desc;
```
Ecrã encomendas do cliente.

**Q6**: Informação do cliente

```sql
select CLI.*, LOCAIS.NOME
from CLIENTE CLI, LOCAIS_DE_ENTREGA LOCAIS, PERTENCE_A PERT
where CLI.ID_CLIENTE = PERT.ID_CLIENTE
and PERT.ID_LOCAL = LOCAIS.ID_LOCAL;
```

Ecrã perfil do cliente

## **Cap 9: Conclusões**

Com o projeto realizado ficámos a entender como se desenvolve uma base de dados para um problema real e como funcionam os mecanismos de bases de dados Oracle.

Desde a lógica geral de arquitetura, até aos comandos de SQL específicos, entendemos todo o processo de desenvolvimento de uma base de dados.

A nossa base de dados visa tornar todo o processo de armazenamento de dados da nossa empresa de distribuição mais eficiente e incomensuravelmente superior às da concorrência.

As entregas eficazes, imediatas e automatizadas são uma tendência cada vez maior no mercado, pelo que faz mais do que sentido criar este novo sistema de entrega de produtos.