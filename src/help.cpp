
#include "help.hpp"

#include <vector>
#include <cmath>

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

void paintit::help(unsigned page)
{
	if(page == 0) return;

	std::vector<std::string> commands =
	{
		"blueequal",
		"brighten",
		"circle",
		"clear",
		"color",
		"crop",
		"curve",
		"darken",
		"desaturate",
		"elipse",
		"exit",
		"fill",
		"glitch",
		"global",
		"grayscale",
		"greenequal",
		"guev",
		"help",
		"history",
		"image",
		"intensity",
		"invert",
		"line",
		"listcolor",
		"negative",
		"open",
		"pixelize",
		"polygon",
		"purge",
		"rbglitch",
		"rect",
		"redequal",
		"rotate",
		"save",
		"sclear",
		"scolor",
		"sepia",
		"size",
		"vibrancy"
	};
	unsigned total_pages = ceil(commands.size() / 10.0f);
	std::cout << " --- Mostrando página " << page << " de " << total_pages << " --- " << std::endl;
	for (size_t i = (page - 1) * 10; i < page * 10 && i < commands.size(); ++i)
	{
		std::cout << commands[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Para consultar a sintaxe e a funcionalidade do comando digite: [comando] /?" << std::endl;
	if(page < total_pages)
		std::cout << "Digite help " << page + 1 << " para visualizar a próxima página." << std::endl;
	std::cout << "--------------------" << std::endl;
}

std::string paintit::command_sintax(const std::string& command)
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
		//return "";
	}
	else if(lib::cstrcmp(command, "global") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "line") == 0)
	{
		return "uso: line [y0] [x0] [y1] [x1]";
	}
	else if(lib::cstrcmp(command, "polygon") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "rect") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "circle") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "fill") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "save") == 0)
	{

	}
	else if(lib::cstrcmp(command, "open") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "scolor") == 0)
	{

	}
	else if(lib::cstrcmp(command, "sclear") == 0)
	{
		//return "";
	}
	/*else if(lib::cstrcmp(command, "rotate") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "invert") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "grayscale") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "sepia") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "negative") == 0)
	{
		//return "";
	}*/
	else if(lib::cstrcmp(command, "glitch") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "rbglitch") == 0)
	{

	}
	else if(lib::cstrcmp(command, "pixelize") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "darken") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "brighten") == 0)
	{

	}
	else if(lib::cstrcmp(command, "vibrancy") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "intensity") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "redequal") == 0)
	{

	}
	else if(lib::cstrcmp(command, "greenequal") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "blueequal") == 0)
	{

	}
	else if(lib::cstrcmp(command, "desaturate") == 0)
	{
		//return "";
	}
	/*else if(lib::cstrcmp(command, "listcolor") == 0)
	{
		//return "";
	}*/
	else if(lib::cstrcmp(command, "curve") == 0)
	{
		//return "";
	}
	else if(lib::cstrcmp(command, "elipse") == 0)
	{
		//return "";
	}
	/*else if(lib::cstrcmp(command, "help") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "purge") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "history") == 0)
	{
		//return "";
	}*/
	/*else if(lib::cstrcmp(command, "exit") == 0)
	{
		//return "";
	}*/
	return "Um exemplo de uso não está disponível para este comando. Favor verificar sua sintaxe";
}

std::string paintit::command_help(const std::string& command)
{
	if(lib::cstrcmp(command, "image") == 0)
	{
		std::cout <<
		"Image: image [largura] [altura]" << std::endl <<
		"\tCria uma nova imagem com a largura e altura especificadas;" << std::endl;
	}
	else if(lib::cstrcmp(command, "color") == 0)
	{
		std::cout <<
		"Color: color [0-255] [0-255] [0-255]" << std::endl <<
		"\tMuda a cor do pincel para os valores rgb vermelho, azul e verde respectivamente;" << std::endl;
	}
	else if(lib::cstrcmp(command, "size") == 0)
	{
		std::cout <<
		"Size: size [tamanho]" << std::endl <<
		"\tAltera o tamanho do pincel para o tamanho informado." << std::endl;
	}
	else if(lib::cstrcmp(command, "guev") == 0)
	{
		std::cout <<
		"Guev: guev [escala]" << std::endl <<
		"\tAplica um estilo Guevara (preto e branco por limiar) na imagem;" << std::endl;
	}
	else if(lib::cstrcmp(command, "clear") == 0)
	{
		std::cout <<
		"Clear: clear [0-255] [0-255] [0-255]" << std::endl <<
		"\tRedefine as cores dos pixeis da imagem para os valores rgb vermelho, azul e verde respectivamente;" << std::endl;
	}
	else if(lib::cstrcmp(command, "global") == 0)
	{
		std::cout <<
		"Global: global [linha] [coluna]" << std::endl <<
		"\tAltera todas as cores idênticas a cor na posição informada para a cor do pincel;" << std::endl;
	}
	else if(lib::cstrcmp(command, "line") == 0)
	{
		std::cout <<
		"Line: line [linha 1] [coluna 1] [linha 2] [coluna 2]" << std::endl <<
		"\tDesenha uma linha de (linha 1, coluna 1) a (linha 2, coluna 2);" << std::endl;
	}
	else if(lib::cstrcmp(command, "polygon") == 0)
	{
		std::cout <<
		"Polygon: polygon [lados] [X1] [Y1] [X2] [Y2] [X3] [Y3] ... [X lados] [Y lados]" << std::endl <<
		"\tCria um polígono com a quantidade de lados especificada, passando pelos \"lados\" pares de pontos;" << std::endl;
	}
	else if(lib::cstrcmp(command, "rect") == 0)
	{
		std::cout <<
		"Rectangle: rect [linha] [coluna] [largura] [altura]" << std::endl <<
		"\tCria um retângulo com largura e altura especificadas;" << std::endl;
	}
	else if(lib::cstrcmp(command, "circle") == 0)
	{
		std::cout <<
		"Circle: circle [linha] [coluna] [raio] [preencher (P)]" << std::endl <<
		"\tDesenha um círculo com raio especificado. Para P > 0 o círculo será preenchido;" << std::endl;
	}
	else if(lib::cstrcmp(command, "fill") == 0)
	{
		std::cout <<
		"Fill: fill [linha] [coluna]" << std::endl <<
		"\tPreenche com cor, a partir de (coluna, linha) todos os pixeis até que seja encontrado um limite, caso não exista, a função preencherá toda a imagem, mantendo o conteúdo preexistente;" << std::endl;
	}
	else if(lib::cstrcmp(command, "save") == 0)
	{
		std::cout <<
		"Save: save [3 ou 6] [caminho]" << std::endl <<
		"\tSalva a imagem no formato P3 (PPMA) ou P6 (PPMB) no diretório especificado;" << std::endl;
	}
	else if(lib::cstrcmp(command, "open") == 0)
	{
		std::cout <<
		"Open: open [caminho]" << std::endl <<
		"\tCarrega um arquivo PPM (binário ou ASCII) preexistente para edição. Outros formatos (ainda) não são suportados;" << std::endl;
	}
	else if(lib::cstrcmp(command, "scolor") == 0)
	{
		std::cout <<
		"Special color: scolor [cor]" << std::endl <<
		"\tAltera a cor do pincel para a cor informada. (Use listcolor para obter a lista de cores que podem ser usadas com esse comando)." << std::endl;
	}
	else if(lib::cstrcmp(command, "sclear") == 0)
	{
		std::cout <<
		"Special clear: sclear [cor]" << std::endl <<
		"\tRedefine as cores dos pixeis da imagem para a cor informada. (Use listcolor para obter a lista de cores que podem ser usadas com esse comando);" << std::endl;
	}
	else if(lib::cstrcmp(command, "rotate") == 0)
	{
		std::cout <<
		"Rotate: rotate" << std::endl <<
		"\tGira a imagem em 90 graus no sentido horário;" << std::endl;
	}
	else if(lib::cstrcmp(command, "invert") == 0)
	{
		std::cout <<
		"Invert: invert" << std::endl <<
		"\tInverte a imagem verticalmente;" << std::endl;
	}
	else if(lib::cstrcmp(command, "grayscale") == 0)
	{
		std::cout <<
		"Gray scale: grayscale" << std::endl <<
		"\tAplica um filtro preto e branco em toda a imagem;" << std::endl;
	}
	else if(lib::cstrcmp(command, "sepia") == 0)
	{
		std::cout <<
		"Sepia: sepia" << std::endl <<
		"\tAplica um filtro sépia (antigo) em toda a imagem;" << std::endl;
	}
	else if(lib::cstrcmp(command, "negative") == 0)
	{
		std::cout <<
		"Negative: negative" << std::endl <<
		"\tAplica um filtro negativo em toda a imagem;" << std::endl;
	}
	else if(lib::cstrcmp(command, "glitch") == 0)
	{
		std::cout <<
		"Glitch: glitch [distancia] [ângulo]" << std::endl <<
		"\tAplica um efeito de distanciamento dos planos de cores de acordo com o ângulo informado;" << std::endl;
	}
	else if(lib::cstrcmp(command, "rbglitch") == 0)
	{
		std::cout <<
		"RBGlitch: rbglitch [distancia] [ângulo]" << std::endl <<
		"\tAplica um efeito de distanciamento dos planos de cores de acordo com o ângulo informado depois de ter aplicado o efeito grayscale;" << std::endl;
	}
	else if(lib::cstrcmp(command, "pixelize") == 0)
	{
		//std::cout <<

	}
	else if(lib::cstrcmp(command, "darken") == 0)
	{
		std::cout <<
		"Darken: darken [0-100]" << std::endl <<
		"\tDiminui o brilho da imagem. Valores altos (ou baixos demais) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "brighten") == 0)
	{
		std::cout <<
		"Brighten: brighten [percentual]" << std::endl <<
		"\tAumenta o brilho da imagem. Valores altos (ou baixos demas) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "vibrancy") == 0)
	{
		std::cout <<
		"Vibrancy: vibrancy [0-100]" << std::endl <<
		"\tAjusta a vibração de cores na imagem de acordo com o percentual especificado. Valores altos (ou baixos demais) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "intensity") == 0)
	{
		std::cout <<
		"Intensity: intensity [0-100] [0-100] [0-100]" << std::endl <<
		"\tAjusta a intensidade de vermelho, verde e azul na imagem. Valores altos (ou baixos demais) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "redequal") == 0)
	{
		std::cout <<
		"Red equalizer: redequal [0-100] [0-100] [0-100]" << std::endl <<
		"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com os níveis originais de vermelho da imagem. Valores altos (ou baixos demais) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "greenequal") == 0)
	{
		std::cout <<
		"Green equalizer: greenequal [0-100] [0-100] [0-100]" << std::endl <<
		"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com os níveis originais de verde da imagem. Valores altos (ou baixos demais) podem provocar a perda de informação;" << std::endl;
	}
	else if(lib::cstrcmp(command, "blueequal") == 0)
	{
		std::cout <<
		"Blue equalizer: blueequal [0-100] [0-100] [0-100]" << std::endl <<
		"\tAjusta a intensidade de vermelho, verde e azul na imagem de acordo com os níveis originais de azul da imagem. Valores altos (ou baixos demais) podem provocar a perda de informação" << std::endl;
	}
	else if(lib::cstrcmp(command, "desaturate") == 0)
	{
		std::cout <<
		"Desaturate: desaturate [0-100] [0-100] [0-100]" << std::endl <<
		"\tProvoca a desaturação dos pixeis que apresentarem um percentual de brilho menor do que o valor informado em vermelho, verde e azul;" << std::endl;
	}
	else if(lib::cstrcmp(command, "listcolor") == 0)
	{
		std::cout <<
		"List color: listcolor" << std::endl <<
		"\tExibe uma mensagem listando algumas cores predefinidas pelo programa;" << std::endl;
	}
	else if(lib::cstrcmp(command, "curve") == 0)
	{
		std::cout <<
		"Curve: curve [pontos] [X1] [Y1] ... [X pontos] [Y pontos]" << std::endl <<
		"\tDesenha uma curva de Bézier de ordem \\\"pontos\\\";" << std::endl;
	}
	else if(lib::cstrcmp(command, "elipse") == 0)
	{
		std::cout <<
		"Elipse: elipse [linha] [coluna] [largura] [altura]" << std::endl <<
		"\tDesenha uma elipse com largura e algura informadas;" << std::endl;
	}
	else if(lib::cstrcmp(command, "help") == 0)
	{
		std::cout <<
		"Help: help" << std::endl <<
		"\tExibe esta mensagem;" << std::endl;
	}
	else if(lib::cstrcmp(command, "purge") == 0)
	{
		std::cout <<
		"Purge: purge" << std::endl <<
		"\tLimpa a tela;" << std::endl;
	}
	else if(lib::cstrcmp(command, "history") == 0)
	{


	}
	else if(lib::cstrcmp(command, "exit") == 0)
	{
		std::cout <<
		"Exit: exit" << std::endl <<
		"\tSai do programa" << std::endl;
	}
	return "Um exemplo de uso não está disponível para este comando. Favor verificar sua sintaxe";
}