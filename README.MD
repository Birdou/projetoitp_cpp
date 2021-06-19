**Habilitar a quebra de texto**

Por Felipe Sena de Medeiros.
Última versão: 18/06/2021 às 22:18

### Descrição geral e recursos

O programa PaintIt dispõe de todas as primitivas gráficas, mais de 40 funções extras divididas em funções derivadas e filtros, tamanho ajustável do pincel e 145 cores HTML [1] que podem ser chamadas pelo nome pelas funções de prefixo 's' [2];

Dentre as derivadas foram implementadas funções de desenhos de elipses e curvas, rotação e inversão de imagens e preenchimento global;

Os filtros de imagem variam de efeitos a correções de cor. O usuário pode escolher entre preto e branco, sépia e negativo ou ainda ajustar o brilho, a intensidade e a vibração das cores da imagem, dessaturar cores específicas, igualar outras, redimensionar a imagem [3] entre várias outras funções de edição;

O programa trabalha com os formatos PPM, BMP, JPG, PNG, TGA, TIFF, WEBP e suas variações, sendo possível também optar por salvar entre os formatos reconhecidos com o comando save;

O usuário tem acesso a lista de comandos, suas respectivas sintaxes e descrição, e ainda a lista de cores divididas por tons de cinza a pastel;

1. Disponíveis em: <https://celke.com.br/artigo/tabela-de-cores-html-nome-hexadecimal-rgb>
2. scolor e sclear
3. Por enquanto só é possível redimensionar a imagem para resoluções menores

### Diretórios

* ./source/ contém todos os arquivos com as funções que compõem o programa principal;
* ./include/ contém todos os arquivos com as assinaturas de funções que compõem o programa principal;
* ./assets/ contém os assets necessários para a execução do programa;
* ./objects/ contém os objetos necessários para a compilação;

### Arquivos

* makefile - contém as instruções de compilação do projeto.
* README.MD - 
* CHANGELOG.TXT - 
* \*.dll - 
 
### Modularização

* AssetManager.cpp - 
* color.cpp - 
* coord.cpp - 
* ECS.cpp - 
* functions.cpp - 
* help.cpp - 
* lib.cpp - 
* main.cp
* paintit.cpp - 
* pencil.cpp - 
* ppm.cpp - 
* processing.cpp - 
* rgb.cpp - 
* TextureManager.cpp - 
* Vector2D.cpp - 
* viewer.cpp - 

	
### Informações técnicas e extras

* Linguagem: C++;
* Compatibilidade: Windows;
* Requisitos para (re)compilação: MinGW 32 com SDL2, SDL_Image e SDL_TTF;
* Compiladores: c++, g++;
* Exceções tratadas: desconhecido;
* Tempo médio de desenvolvimento: +120h;
* Funções: 60 +;
* Fim de linha (arquivos salvos): CR (Carriage return, Mac Os);
* Interface: Sim;
* Conceitos matemáticos utilizados: Matriz de rotação, fatorial, binômio de Newton, geometria analítica, aritmética, planos Cartesianos;
* Versão: 2.4.0 +
	
### Makefile

* make all: Constrói os binários do projeto e linka o executável.
* make clean: Apaga os arquivos utilizados durante a compilação, assim como seus respectivos binários finais.

