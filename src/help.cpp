
#include "help.hpp"

#include "lib.hpp"

void paintit::listcolor()
{
	std::cout << std::endl <<
	"Tons de cinza:"														<< std::endl <<
	"                Black,                 White,                grey11,"	<< std::endl <<
	"               grey21,                grey31,               DimGray,"	<< std::endl <<
	"                 Gray,              DarkGray,                Silver,"	<< std::endl <<
	"            LightGrey,             Gainsboro." 						<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de azul:"															<< std::endl <<
	"            SlateBlue,            SlateBlue1,            SlateBlue3,"	<< std::endl <<
	"        DarkSlateBlue,          MidnightBlue,                  Navy,"	<< std::endl <<
	"             DarkBlue,            MediumBlue,                  Blue,"	<< std::endl <<
	"       CornflowerBlue,             RoyalBlue,            DodgerBlue,"	<< std::endl <<
	"          DeepSkyBlue,          LightSkyBlue,               SkyBlue,"	<< std::endl <<
	"            LightBlue,             SteelBlue,        LightSteelBlue,"	<< std::endl <<
	"            SlateGray,        LightSlateGray."							<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de ciano:"														<< std::endl <<
	"                 Aqua,                  Cyan,         DarkTurquoise,"	<< std::endl <<
	"            Turquoise,       MediumTurquoise,         LightSeaGreen,"	<< std::endl <<
	"             DarkCyan,                  Teal,            Aquamarine,"	<< std::endl <<
	"     MediumAquamarine,             CadetBlue."							<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de verde:"														<< std::endl <<
	"        DarkSlateGray,     MediumSpringGreen,           SpringGreen,"	<< std::endl <<
	"            PaleGreen,            LightGreen,          DarkSeaGreen,"	<< std::endl <<
	"       MediumSeaGreen,              SeaGreen,             DarkGreen,"	<< std::endl <<
	"                Green,           ForestGreen,             LimeGreen,"	<< std::endl <<
	"                 Lime,             LawnGreen,            Chartreuse,"	<< std::endl <<
	"          GreenYellow,           YellowGreen,             OliveDrab,"	<< std::endl <<
	"       DarkOliveGreen,                 Olive,"							<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de marrom:"														<< std::endl <<
	"            DarkKhaki,             Goldenrod,         DarkGoldenrod,"	<< std::endl <<
	"          SaddleBrown,                Sienna,             RosyBrown,"	<< std::endl <<
	"                 Peru,             Chocolate,            SandyBrown,"	<< std::endl <<
	"          NavajoWhite,                 Wheat,             BurlyWood,"	<< std::endl <<
	"                  Tan."												<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de roxo:"															<< std::endl <<
	"      MediumSlateBlue,          MediumPurple,            BlueViolet,"	<< std::endl <<
	"               Indigo,            DarkViolet,            DarkOrchid,"	<< std::endl <<
	"         MediumOrchid,                Purple,           DarkMagenta,"	<< std::endl <<
	"              Fuchsia,               Magenta,                Violet,"	<< std::endl <<
	"               Orchid,                  Plum."							<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de rosa:"															<< std::endl <<
	"      MediumVioletRed,              DeepPink,               HotPink,"	<< std::endl <<
	"        PaleVioletRed,             LightPink,                  Pink,"	<< std::endl <<
	"           LightCoral,             IndianRed,               Crimson."	<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de vermelho:"														<< std::endl <<
	"               Maroon,               DarkRed,             FireBrick,"	<< std::endl <<
	"                Brown,                Salmon,            DarkSalmon,"	<< std::endl <<
	"          LightSalmon,                 Coral,                Tomato,"	<< std::endl <<
	"                  Red."												<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de laranja:"														<< std::endl <<
	"            OrangeRed,            DarkOrange,                Orange."	<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons de amarelo:"														<< std::endl <<
	"                 Gold,                Yellow,                 Khaki."	<< std::endl <<
	"------------------------"												<< std::endl <<
	"Tons pastel:"															<< std::endl <<
	"            AliceBlue,            GhostWhite,                  Snow,"	<< std::endl <<
	"             Seashell,           FloralWhite,            WhiteSmoke,"	<< std::endl <<
	"                Beige,               OldLace,                 Ivory,"	<< std::endl <<
	"                Linen,              Cornsilk,          AntiqueWhite,"	<< std::endl <<
	"       BlanchedAlmond,                Bisque,           LightYellow,"	<< std::endl <<
	"         LemonChiffon,  LightGoldenrodYellow,            PapayaWhip,"	<< std::endl <<
	"            PeachPuff,              Moccasin,         PaleGoldenrod,"	<< std::endl <<
	"            MistyRose,         LavenderBlush,              Lavender,"	<< std::endl <<
	"              Thistle,                 Azure,             LightCyan,"	<< std::endl <<
	"           PowderBlue,         PaleTurquoise,              Honeydew,"	<< std::endl <<
	"            MintCream." 												<< std::endl <<
	"------------------------"												<< std::endl <<
	"Para usar uma cor pelo nome, use scolor [nome_da_cor] ou sclear [nome_da_cor]." << std::endl <<
	"------------------------"												<< std::endl;
}

void paintit::help ()
{
	std::cout << std::endl <<
	"Blue equalizer: blueequal [0-100] [0-100] [0-100]"									<< std::endl <<
	"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com"			<< std::endl <<
	"os níveis originais de azul da imagem. Valores altos (ou baixos demais)"			<< std::endl <<
	"podem provocar a perda de informação;"												<< std::endl <<
	"------------------------"															<< std::endl <<
	"Brighten: brighten [percentual]"													<< std::endl <<
	"\tAumenta o brilho da imagem. Valores altos (ou baixos demas) podem"				<< std::endl <<
	"provocar a perda de informação;"													<< std::endl <<
	"------------------------"															<< std::endl <<
	"Circle: circle [linha] [coluna] [raio] [preencher (P)]"							<< std::endl <<
	"\tDesenha um círculo com raio especificado. Para P > 0 o círculo será"				<< std::endl <<
	"preenchido;"																		<< std::endl <<
	"------------------------"															<< std::endl <<
	"Clear: clear [0-255] [0-255] [0-255]"												<< std::endl <<
	"\tRedefine as cores dos pixeis da imagem para os valores pit::rgb vermelho,"		<< std::endl <<
	"azul e verde respectivamente;"														<< std::endl <<
	"------------------------"															<< std::endl <<
	"Color: color [0-255] [0-255] [0-255]"												<< std::endl <<
	"\tMuda a cor do pincel para os valores pit::rgb vermelho, azul e verde"			<< std::endl <<
	"respectivamente;"																	<< std::endl <<
	"------------------------"															<< std::endl <<
	"Comp: comp [caminho 1] [caminho 2]"												<< std::endl <<
	"\tComprime uma imagem PPM ou descomprime, caso esta esteja comprimida, e"			<< std::endl <<
	"salva em \'caminho 2\'"															<< std::endl <<
	"------------------------"															<< std::endl <<
	"Curve: curve [pontos] [X1] [Y1] ... [X pontos] [Y pontos]"							<< std::endl <<
	"\tDesenha uma curva de Bézier de ordem \\\"pontos\\\";"							<< std::endl <<
	"------------------------"															<< std::endl <<
	"Darken: darken [0-100]"															<< std::endl <<
	"\tDiminui o brilho da imagem. Valores altos (ou baixos demais) podem"				<< std::endl <<
	"provocar a perda de informação;"													<< std::endl <<
	"------------------------"															<< std::endl <<
	"Desaturate: desaturate [0-100] [0-100] [0-100]"									<< std::endl <<
	"\tProvoca a desaturação dos pixeis que apresentarem um percentual de"				<< std::endl <<
	"brilho menor do que o valor informado em vermelho, verde e azul;"					<< std::endl <<
	"------------------------"															<< std::endl <<
	"Elipse: elipse [linha] [coluna] [largura] [altura]"								<< std::endl <<
	"\tDesenha uma elipse com largura e algura informadas;"								<< std::endl <<
	"------------------------"															<< std::endl <<
	"Exit: exit"																		<< std::endl <<
	"\tSai do programa e libera a memória antes utilizada para a manipulação da"		<< std::endl <<
	"imagem;"																			<< std::endl <<
	"------------------------"															<< std::endl <<
	"Fill: fill [linha] [coluna]"														<< std::endl <<
	"\tPreenche com cor, a partir de (coluna, linha) todos os pixeis até que"			<< std::endl <<
	"seja encontrado um limite, caso não exista, a função preencherá toda a"			<< std::endl <<
	"imagem, mantendo o conteúdo preexistente;"											<< std::endl <<
	"------------------------"															<< std::endl <<
	"From file: fromfile [arquivo]"														<< std::endl <<
	"\tCarrega um algoritmo para a criação de uma imagem;"								<< std::endl <<
	"------------------------"															<< std::endl <<
	"Glitch: glitch [distancia] [ângulo]"												<< std::endl <<
	"\tAplica um efeito de distanciamento dos planos de cores de acordo com o"			<< std::endl <<
	"ângulo informado;"																	<< std::endl <<
	"------------------------"															<< std::endl <<
	"Global: global [linha] [coluna]"													<< std::endl <<
	"\tAltera todas as cores idênticas a cor na posição informada para a cor do"		<< std::endl <<
	"pincel;"																			<< std::endl <<
	"------------------------"															<< std::endl <<
	"Gray scale: grayscale"																<< std::endl <<
	"\tAplica um filtro preto e branco em toda a imagem;"								<< std::endl <<
	"------------------------"															<< std::endl <<
	"Green equalizer: greenequal [0-100] [0-100] [0-100]"								<< std::endl <<
	"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com"			<< std::endl <<
	"os níveis originais de verde da imagem. Valores altos (ou baixos demais)"			<< std::endl <<
	"podem provocar a perda de informação;"												<< std::endl <<
	"------------------------"															<< std::endl <<
	"Guev: guev [escala]"																<< std::endl <<
	"\tAplica um estilo Guevara (preto e branco por limiar) na imagem;"					<< std::endl <<
	"\t"																				<< std::endl <<
	"------------------------"															<< std::endl <<
	"Help: help"																		<< std::endl <<
	"\tExibe esta mensagem;"															<< std::endl <<
	"------------------------"															<< std::endl <<
	"Image: image [largura] [altura]"													<< std::endl <<
	"\tCria uma nova imagem com a largura e altura especificadas;"						<< std::endl <<
	"------------------------"															<< std::endl <<
	"Intensity: intensity [0-100] [0-100] [0-100]"										<< std::endl <<
	"\tAjusta a intensidade de vermelho, verde e azul na imagem. Valores altos"			<< std::endl <<
	"(ou baixos demais) podem provocar a perda de informação;"							<< std::endl <<
	"------------------------"															<< std::endl <<
	"Invert: invert"																	<< std::endl <<
	"\tInverte a imagem verticalmente;"													<< std::endl <<
	"------------------------"															<< std::endl <<
	"Line: line [linha 1] [coluna 1] [linha 2] [coluna 2]"								<< std::endl <<
	"\tDesenha uma linha de (linha 1, coluna 1) a (linha 2, coluna 2);"					<< std::endl <<
	"------------------------"															<< std::endl <<
	"List color: listcolor"																<< std::endl <<
	"\tExibe uma mensagem listando algumas cores predefinidas pelo programa;"			<< std::endl <<
	"------------------------"															<< std::endl <<
	"Negative: negative"																<< std::endl <<
	"\tAplica um filtro negativo em toda a imagem;"										<< std::endl <<
	"------------------------"															<< std::endl <<
	"Open: open [caminho]"																<< std::endl <<
	"\tCarrega um arquivo PPM (binário ou ASCII) preexistente para edição."				<< std::endl <<
	"Outros formatos (ainda) não são suportados;"										<< std::endl <<
	"------------------------"															<< std::endl <<
	"Pixelize: pixelize [pixels]"														<< std::endl <<
	"\tCria um efeito de pixelização. O valor informado definirá o tamanho do"			<< std::endl <<
	"novo pixel;"																		<< std::endl <<
	"------------------------"															<< std::endl <<
	"Polygon: polygon [lados] [X1] [Y1] [X2] [Y2] [X3] [Y3] ... [X lados] [Y lados]"	<< std::endl <<
	"\tCria um polígono com a quantidade de lados especificada, passando pelos"			<< std::endl <<
	"\"lados\" pares de pontos;"														<< std::endl <<
	"------------------------"															<< std::endl <<
	"Purge: purge"																		<< std::endl <<
	"\tLimpa a tela;"																	<< std::endl <<
	"------------------------"															<< std::endl <<
	"RBGlitch: rbglitch [distancia] [ângulo]"											<< std::endl <<
	"\tAplica um efeito de distanciamento dos planos de cores de acordo com o"			<< std::endl <<
	"ângulo informado depois de ter aplicado o efeito grayscale;"						<< std::endl <<
	"------------------------"															<< std::endl <<
	"Rectangle: rect [linha] [coluna] [largura] [altura]"								<< std::endl <<
	"\tCria um retângulo com largura e altura especificadas;"							<< std::endl <<
	"------------------------"															<< std::endl <<
	"Red equalizer: redequal [0-100] [0-100] [0-100]"									<< std::endl <<
	"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com"			<< std::endl <<
	"os níveis originais de vermelho da imagem. Valores altos (ou baixos demais)"		<< std::endl <<
	"podem provocar a perda de informação;"												<< std::endl <<
	"------------------------"															<< std::endl <<
	"Rotate: rotate"																	<< std::endl <<
	"\tGira a imagem em 90 graus no sentido horário;"									<< std::endl <<
	"------------------------"															<< std::endl <<
	"Save: save [3 ou 6] [caminho]"														<< std::endl <<
	"\tSalva a imagem no formato P3 (PPMA) ou P6 (PPMB) no diretório"					<< std::endl <<
	"especificado;"																		<< std::endl <<
	"------------------------"															<< std::endl <<
	"Special clear: sclear [cor]"														<< std::endl <<
	"\tRedefine as cores dos pixeis da imagem para a cor informada. (Use"				<< std::endl <<
	"listcolor para obter a lista de cores que podem ser usadas com esse"				<< std::endl <<
	"comando);"																			<< std::endl <<
	"------------------------"															<< std::endl <<
	"Special color: scolor [cor]"														<< std::endl <<
	"\tAltera a cor do pincel para a cor informada. (Use listcolor para obter a"		<< std::endl <<
	"lista de cores que podem ser usadas com esse comando)."							<< std::endl <<
	"------------------------"															<< std::endl <<
	"Sepia: sepia"																		<< std::endl <<
	"\tAplica um filtro sépia (antigo) em toda a imagem;"								<< std::endl <<
	"------------------------"															<< std::endl <<
	"Size: size [tamanho]"																<< std::endl <<
	"\tAltera o tamanho do pincel para o tamanho informado."							<< std::endl <<
	"------------------------"															<< std::endl <<
	"Undo: undo"																		<< std::endl <<
	"\tDesfaz a última alteração feita na imagem;"										<< std::endl <<
	"------------------------"															<< std::endl <<
	"Vibrancy: vibrancy [0-100]"														<< std::endl <<
	"\tAjusta a vibração de cores na imagem de acordo com o percentual"					<< std::endl <<
	"especificado. Valores altos (ou baixos demais) podem provocar a perda de"			<< std::endl <<
	"informação;"																		<< std::endl <<
	"------------------------"															<< std::endl;
}
std::string paintit::commandHelp(const std::string& command)
{
	if(lib::cstrcmp(command, "image") == 0)
	{
		return "uso: image [largura] [altura]";
	}
	else if(lib::cstrcmp(command, "color") == 0)
	{
		return "uso: color [r] [g] [b]";
	}
	else if(lib::cstrcmp(command, "size") == 0)
	{
		return "uso: size [tamanho]";
	}
	else if(lib::cstrcmp(command, "guev") == 0)
	{
		return "uso: guev [escala]";
	}
	else if(lib::cstrcmp(command, "clear") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "global") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "line") == 0)
	{
		return "uso: line [y0] [x0] [y1] [x1]";
	}
	else if(lib::cstrcmp(command, "polygon") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "rect") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "circle") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "fill") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "save") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "open") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "scolor") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "sclear") == 0)
	{
		return "";
	}
	/*else if(lib::cstrcmp(command, "rotate") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "invert") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "grayscale") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "sepia") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "negative") == 0)
	{
		return "";
	}*/
	else if(lib::cstrcmp(command, "glitch") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "rbglitch") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "pixelize") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "darken") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "brighten") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "vibrancy") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "intensity") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "redequal") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "greenequal") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "blueequal") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "desaturate") == 0)
	{
		return "";
	}
	/*else if(lib::cstrcmp(command, "listcolor") == 0)
	{
		return "";
	}*/
	else if(lib::cstrcmp(command, "curve") == 0)
	{
		return "";
	}
	else if(lib::cstrcmp(command, "elipse") == 0)
	{
		return "";
	}
	/*else if(lib::cstrcmp(command, "help") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "purge") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "history") == 0)
	{
		return "";
	}*/
	/*else if(lib::cstrcmp(command, "exit") == 0)
	{
		return "";
	}*/
}