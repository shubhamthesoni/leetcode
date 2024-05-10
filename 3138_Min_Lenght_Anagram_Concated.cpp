#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    int validateAnagram(string s, int k)
    {
      int len = s.length();
      if(len == k) return k;
      string temp = s.substr(0, k);
      sort(temp.begin(), temp.end());
      //cout << "After Sort : "<<temp<<endl;

      for(int i = k; i < len; i = i+k)
      {
        string temp2 = s.substr(i, k);
        sort(temp2.begin(), temp2.end());
        if(temp2 != temp) return INT_MAX;
      }
      return k;
    }

    int minAnagramLength(string s) {
       int len = s.length();
       if(len == 0) return 0;
       if(len == 1) return 1;

       map<int, int> M;
       int minDiv = INT_MAX;
       for(char data: s) { ++M[data-'a']; }
       for(auto itr = M.begin(); itr != M.end(); itr++) minDiv = min(minDiv, itr->second); 

       /* We have the min divisor */
       cout << "length : "<<len<<" MinDiv : "<<minDiv<<endl;
       minDiv = len/minDiv;
       cout << "Min Div : "<<minDiv<<endl;
       int minAnagram = len;
       for(int i = 1; i < len/minDiv; i++)
       {
         cout << "Value of i*minDiv "<< i*minDiv<<endl;
         minAnagram = min(minAnagram, validateAnagram(s, i*minDiv));
       }
       return minAnagram;
    }
};


int main()
{
  Solution solution;
  cout << solution.minAnagramLength("abba")<<endl;
  cout << solution.minAnagramLength("cdef")<<endl;
  cout << solution.minAnagramLength("nqazgrrkovypkksgsdgqmoudzsnqjnkylnjucoyjcskgdsutmmckuaesggrbuvccjfqvdkonndoznnwzqgxkojwyzdqoosknyzsgprzuyxmcayvjfaxywkiclnmrmmfgeewdfrlwbjiveuwadzwlftfqymusyxkgrnizvbtawhlikfiqnolqyvntdzeiywlglgfvqgvmnsaaqolgxerpjaepxwqihyyzgtzfcledhhxspelmmsjqnemsnlblboyymtdfkimumjmchxfiaewyxhgbawlcpjeufcgoukawgguetpyqjijgljnpkewkpajdtbyeqdjbkwqsecjnryboxipphsfvdrwbprkkmyrdpesaccpthltikpbcsbdxokggqirizunrcaepgngjjmtmxqutvsdztylcxskffklbncecscgmtsiyzdxnllctppzixlmgorebhnxhivwparsslnuzcclrbdkvqbmdfuxkqilvyerpnzdadvhzstvgzjtwvztwqapynevvuplgfntubnwqvrxkeqrlysbwbqvhwjyvfkliqwhwzhugbtwrcsjvncnuqelwqczsjxtexlzagmrzihbkdlqchyyumuqrfxtaehaqpzftbhqnpxltqwdelyppageuzlmmzboynkapajtbjudobqfcegdaoaaxiqerguqvcpjjjiwcsnawyakgwhxkbkkramtbctolrvhyiceibxkjgxmsbbwinrtipafrolougbtkysczktdiwprszsqkhezrvxzlscbiqqbrxmyqgdjjhwksskacfjrxtnqaquekagkzftfeztkpemaqeyogjkpavgfemfvkefttjhscusvoxtiibqtxsxcxlttegnxgeginlnwcoujltoedywxfwhvogpuxbxoyasjfvmunzdlyvghlvtjjshgrphlcvzrxrijnnmocyukkdxuqfsdmerjdkrikoiksukgonfefjnnykaycqxgsozwyeyhshjqsqhydkawlvcjpoickfujjjilfussebdsqauuwiddybftoprzcvmsmnwcceaaiuhptaufudebwowynctapgregphfyenmiztwgfhnhptejqzqbpyuyzldgovezlcpiajbwpkmaekndmfljwouujqqrspbtszslbubqojrwrgossriiywzhcgelgukuxvmaajrepdzkqvaohpeoeyjbnrjdcaowprqzcuocgwefjlayqesjcxebsijiuycdqxlqtjimxabzdhvtbchjtncjuvhkanbzzpylltsyobckgujjfoalsxddtjkyxbdhhyraznwhtmwmosahdmitaiazctxqzlbrpmgfktvoumruqtioziowchzyezghaqilibobxfsmujgtzfnspykwyynpsbvsvaaifhzxpxtfpzlevigkxejnymasxulfqpgqwaolkrcucqpuyvpnswjkweobiqnrexggtojfaalptbdowkmzlqagzsnyqcbgqclpwarzyafmchenuuqvgkqsfsdnldrqkozgmgrcxebqjcuwfipgthwotsmmohjmhqlsgtytzooaaamiombkqtnrsytspjekupymzulxbicuixiwyhhahkoivlajcbsykbxfjhpskmjsrdbmzltjelbdomckqeikymezztyueelcmlgalentqhlpcpxgeqoclxacjysqjtwgpwacfgpfyiuucvdnzcceeefcjyljkiqtdisijljlkmgwvumqaitzwmqpdbashexxyrrdeukglehwbyxkahgbbxrfkacxukcwcnglwfnttnyrvyusescvsrleluqevviognhgucgvdyisgaxjmcnwnfelswrexkpmfsnizwstgoclapgklecljhweqqqgrtpjzmjydeehnzbuprbmxrqrzakwxecksisuzuqyhpapdbhdeggteblsbcstuacrtorcfxauyyruigmvfjkkuotfwrdxaazvatraajujnztedkkajajxjkyxiphrbkqytntsecwsjpsbbawzzogsqobxwehatejjeiayvktozzyxcpuggfhrkklzgwdnvywiwfowkiqyiawenitornkkruunwwwmhgclxechxaqqhtzcejovclmiiygjjfdrftsmnoylngyainbofqrqzcjrnxvhbfcreniuyjrxvyuzuqkldjpjgjyupiydvmuhcesohywqsagcdgjqaepftvkhpktczvliyzaujexvbwojrtbcknllkhsooddvblbgcuykecgvnwdwlyqslfsuysjmzjhdtxjxjjekejnzkdqqnopvimspsqmsrerqnmcfgsgdcywzradngubeuihpaunaxgauomvkqqbzgyloniszksntzgutvizhjrkhvrvsnoviwypvbmefyxvldodfajyjdfgrmgqfsmwptdrmmukeqtngxbhjuzqsjpdjpfqclqsrwzblqnsmfkeowioqcperyknzejdqfktmgllnjatcykcowsivdkvqrbtwjyknoqtkqdvodqgbrhahitruszcnywpzaycbzoderhpljibftvowmobrisxqyfanfmcvjdhnzwizotxycbxtblehmzxwzhbhbupiulxvdmafpewldocmkdqetxuxbdzackcxlwuwefutnfidorgfaqmeobvhjsoavupstdjytlzjssnbllzkhjgzgcgpznpyzrpbkjdwgpkuatbxnditkzqdxtdigprnytuzsgbkmletkjdtnwhegpnlnlfpdfapothuwctbirkbbgahoatkwfzjobiqxnurzrmmeakwzeiaaktwgednjawsusplgfhfcellglifisgbcumiwifoebgicqxejclqhnjjkuenwdubpqojfjjopcnhneymtjhycshvofbcmbqkalcwjyjtbrkxoazlyoxlpkiegheonmbyetnhqwfdgxocbtnjohrpskglcokllkhcpklcgmjsfxjrbxkpaftspukkrsgjaooqceieowqpbzpuctiidyvfuqxtymwfhcoktvvynqzzjbhetasrzhvsqhocemyennybimgqigmsialwkwlurodpozrxdktphbjsyzwasxjcwigbsiwrtglcnaglttuavuwydareyyazaazyckxeuazfeutdycycljfcyelrcfqjkunriqfndtgjlqkbzvvzrjqbjvhwqvvlattxuafwgqbnpjhwdvthdmetynrumxiwnzrbvensyjrjjuicasqsxeivueflpyekougpctuvsgudguungdkjnhggbgseqwvzxxdxmtvhggqoywdgeexcqsylmllipxleduwlsqcsfkmnopidbtjgimggjjpiiostkxekusjvzyztaskyburtqlhnavuqoxagdceqytymmoavcjrliwlzcldvfcbbqdzahuhouzjqeypqbcztcjodtwpyxzjsichtlqskobxajspozjipmrpxrcbbkkdlvyzbdfemrvtamahssyplqxkuqardaljzbtrodtqprqcfnzrwywbswhxngysnauqbppmenxorxrfqqflkqigmskgyhdeqwgsedxgyktpsydktexuixekjupzmtjkpgjnyoqnoawuysetrdqvnadogkdkkkscsxdevrxkaoaysnevgpcxmscsdegmqqoqfgwikkmxvxyrvtdhigzycfpsudltrrudlxipewtrdaocjthmzkopccnhalxjzentdlvwuslzxiwbvuyepybivktejwzhdeepztitqhubvxiktjpbtleqqavkvngokkbncizcsxljyqfmcmnzprjkqfyzebxavqzvxywaplmvufmgjsutscnchgdggczifaommydsvgnwmhnibqhjweqplxblhqigaysxvbtzgnsjvswhzsdrcawuawtukwrpuvlvaccgnfrjfylirapdqeelkogntrlnwsouioahmbnakqwwbdqbyedhznzrrfhumqjmjlkajfkqowpfzkaztauuminxjzjrgonjlmkejcwfigigmelmkygfrpcxzqjueyaosffssybnsyzyccqopzszajnhzuyearuwwidjfyhsrziyfmwcrbbrypznmciynsbbteagwmygrddytujwvtyhecqtnkabwjhaiogpedceuvzxtppftgudizfragzitckobqwzgrgaocbriknoijmcvrqnjsxzwnaezgldwpvtwucpwlpujejzxdqcolgrocdubqcwhvtglssrrrriupcasethtjnuggdbuaurjzpyztpkxihqksqgyqozwfgscesspxrdxpptudkeyqljptswpkomqmqxchnahzzohblkxnvfgdaommlwlotjpsdcnzdtspwwxpykwftdimcfeicmoyzqobceylbfxogtxfrnrncqoqswjfetykspekzwvhjraqixqdtslivarcnbqumlzblytlibioanxclbilnjywqewdublauqghjntencyrjralmkinvjrpwfgfzmnfjckwbfigmyjoktwntdtgvrqiyicramykfnszoagybjpgzfsslmhseecnhjsemilkzictaejiiiszznxdjetxrbqyhlgkuhwywegrqjpqnuqwucnjzajrvkjnmgszuytrxdmhkxctbgkzckqkxlimfnscedjcgtfhlvtotqclwjvkrvwhxvcubaucwembpuxkevyzpyswubdjyelmmrpagfscbouuckyydrduemyechdxoraakiqzoznejhqnfpmfxqgafblibgpkysxecfukepsjeipwbcuoqqyeojtrcbyrhdjqkrljdeqnkdyfjyykgkkjkgsktjuudsymeprnjeitssrtdazxlhaccsjilgcisxbsyrsqvmaxvgvxoiupmsaoyfxjdyrvumuppvloiyyshepcmrdtutfiheshkqyoefqsgynrjjzyubvexzfwhwqztgubwoagimrskiypzcsnxhrkzaoffjzvhvymdhnqhcnaxdaiojznkayxinlfuwymgtefadlatwwyqhscjqlxoaaqtlwczlzibqqabejaepkgyyarwqxnrsmectfnokbvcbzkioqacveqvaoohdjvxcuchkyedozzogdjxybkeydtqbxaetwzeeuxkjlewdfacowwjzhmduxnsmsslngjstybagaqyfserpslulaleqmzvmaesgoipxnljkvlqgqonwagiwkksgvkekhlbymgddjlrqovkinpqzmgbrudfpkuvkfbzbmuhigdaqmpuvoodwzyqumfwiqprztgaxisglttnlhplxoziklzvantqubwltkvwwhkzcqawqdltfmjhamoktpjpkbebvbxgjsfwuxjgvfjppnszkyngmcphhxtbbvackufhbtelfnigptjmjgngdkwsxclrcdnaalsiueqzefggvejolsvscayztnxlsbvhujrbcmjhlnyeunbuprozhuknejdbmwtzszdudetibwskcuhggaewojozyfdpaatcwwkwszyaxqeobayawjnqjvuybzgehuzzexwxufkaippgnqxmzoytmshgnrqlcettkcwzfrvtxzejcuqfvjnsyrmyyunmqisqelxiuugutngmzwkbwsdxbtufsvzqkaeaogwjlydtzyrzevrxuhgkubftqycjafszeyhrlfeajilxqoqyuvuafykqbqbawgynucxcatztvxhjudqmdlwedrthxpeybouaikarbeicdmoqisghxcpprdsyiwirsuyknugxjknidgfrntkxbcsskavvsqbsnaifuqgblojctfdpklnttkccpjpqyimxxeglplfeessemyvysfdpkhsowqkvmqswrvfqdsehmkncxolrqqretozpysyouusqkqsetiluqpbqqcykppftujyxbkoybyrrdmzifsbtlggxojnrbqasxhvizjuhqicpfbhlcyucrcmkitndajdowxacetgbqxgozwsnkkayjewayuyccsnemdojcpgwzorjtqnyjvqvhjphbuxadncidwyrasocpzdgjkmjeqnmllrlwgjjlqndmyzjxlwrrgzkvyluexbcarjqylcwwvolgpepwyfginvehhhylihanolkomjxnyydjmekpeczuqzkktkgkletvzikarakvaxjaitsetbktkypqzmmkysnyhnatthebglcmdtleajgrwcunpjoliysvqbaukimngoywhibvaisqnwzldlufdgboiwhzplkrxefvnclcmwqzfjzjaocsxqghzzovymbfpolzpocjblkciccrcmzthtjqcctxwvonvtrdwtfowjyesdnqiifgpwhelyngwwchgksbgnrdzivsoalzjtsmsnldthnluhmqgmcpvtoikutejrfathndmuxgqosmrsadphahzgaphedgeuixhaystvgklouofdmicgnxtalgcuiphkjxqjjitekfgpdbjiqslieeuggmyfgprqswmfjsdswwzotnstdnntsclxxhvshgsfrkocorzoqpxjpeuupskeybvoxmojknatxidbawjimykidryynswrsgnycfwngkpkddpjtpzcfutlgumbzzdlkebkcezbfyrznjrtnlauufghipoueozwakjlhbvkncnlstkjzphxcesrcejlfadwpmepbhlgiuwivfwwvhlqmmajirkeajjhsrqutamcqfzzkvcrbcfsqabggtwukmjgsbfjaijjwjpdmgoplqepfodrxeblvbbynyeaibajqeccrqqgivvmzrxbzhqylvnrxgvfuavfaxpcxbobkdjzvbdepllguxaewrrmtnqzzbqcxxllaandrpcjiefitglkqccnzqsbqiknpyynsygflnqwhfvbshqqqgkfgesnasgqqksefatpnwutuzaejdkaajaxsfrmakpywsyjlwepvwuanwtsbsvfjozpfynmnjwnxfvbyxnljwurwsigpnxysrgugrtynntcqzkkramiwhjzcqnulxufnjzaettkkrikkrschtojcoafeyxdcowqhxuhtgwuagiatyswwyfuzjywkscaxipzffszxcbddlgolhcbzsvgaovvrthywgzzprusrboddjgovlnghrrtekystgsvdspxzxtmlhphmbewadepzakvewpheqihbhtfkqvfbeujijdniwboqxqtghcubjvvdgkjnqtildkxlvvbccmadvszsyefzzugtozzgptvelxdrjymarjxpjamsaozsltnxuzoukjectsojltjzxebtkijtroqwkauvccjnxyvhoohokimotkpwcgiacttlukgljhycekgtnwnezxvxqjjtpmxuqqzrpgkxaywydkduvvdvekqhgkwbudqhizbpdggnaucujpfmxxqczkemgcrmoqnwkhnqzowzuitiiyzqlrkbmyswnayonrnbqasvcpbobmvuypxtqntlowbqgyfxslewewegsiucrnrlsjjuzopipgxcxxqwkmvxyayjgkznqefuwaqvaamzjeksbinpqcwqljflrptmgsryrfdntacpbodnulitnxyhkspmqgsyibirnreragpsxjdlfggmgbjcjazdqjlbucjjqcgnudetxkghepadmdbapgvmjunuksrkiclobswuligvsrqqzhqyoxmhbszuhkdlbecvddalyzynmflcknumqgdhqflondlecsmokbcerrylumumdqpjglnhtmzmwoykcymsyotvrtjjbxioytwkmcgottojjbqcjfflspdznjlnmavstzbgyntmwgclcwbrokswpixfcvgswclosejewlvlbaketyxuplxriseckseblkqfjkkjdzpfeekahwkfhkueepgavmuudejxtbdzcqnjrjpmphbbqpfgqimxacekfwsqacibcjeiqeebybqatyiohddapdqtyzxpiyooolemjgshyycgdubxweokkreohvbeukfdzzatonpfsyexbqmilsfyryivapfzhovezzdvliajyvvqpskletclnoacdpizerthdhbsqiqzbojumwohhzpeygdgxmearpbwnlxmzicgjfzpywaregjftirjmkyyuwnfdzsyliulftaltwdshuqaiwzbmgumciurzrjhccatkwjlrebdihrechuierakihucqmirjvucgwarlonygytyfsfsruifklicwrqvpcgngnnrbdjyhxolqejsokntbybbyyfqzsigoaatrjyjezllxtcmbulhjaskgcipyoxjcrupsinxegzgjqltkurwqwksanajpgwkpokqlozaggnuknfrbynvkcokwaeozjidfiamkjkxedotgothccykmpctprrkyrssdrpgeviibnaflekokiesozefzpknzangcegdtdjkquqevnybajlblecxgqztqeskiwoyztrmkqvtgvkqjjjvnjzyazpddjerabqplzqeenaubfftdscpxzzuvjgllfqcpkqvuaerqiqwdxzqbylxwihnlzntwxvirjtnzdqvxsslpesasgcespemnyqvyhoarchuquiikgvbxzfwxeihjtvhsccqxcrzfswwmqeqaqllgsvbnasiartnseywcmswbiuwtfkfnnbpkegsfkhexjojseufkmcpiyjzeiyizuyezgvmeypyiqusytkupbxdyzkwaafunsuefhgalruvxlthkntdtcehhyzvwszopchroqfktkyvizesskrqgdlcokkbzzohfjxbywuguccgbxifypnazsiouulxowvflooguoecnazwatqeccckmzsqosmzwubkzghcxyylwnatpzanuewvksegihmuhmtseyavypnlrckjeiaxoxqyqawmdcypqmuisubvbdslucxowxmwjknpgyntlthkgmkhwqhukacamumswtoicsxhutmjgisngulocghadgejsagwlrvkzlytwjjltdblkotmzjcghcnyzjkgtnlidtbxlmenpdumesamifysnyvuudmymrdvqdwbkhjlerfurntdizdbhdwerjdmaftypswdnajzxwabfojlofuiiyxddpmzeagfnidbgumebcmsqbjdgupsrcbykgkxxjmyojkzwgslrzkjvpejajflusawiyqhfqilwbqrkjqljflwgfbcwcdqzisepttfmzeaauzixxianqmrrrmrcpfdmvwcphbbgvajztyenbymbxklphxhpqakbbgpuhnlqlhfcvotakrzmwfjdyfntxzorlhxrgbayovewkrbxbtkwuavjdblmqdetnsvmjrzcgppqkqqxccxistnbnbhxrdgelzzjuhiorsstgeqscdjppjpqzpajjzlrhposmsthwvxaksbtbdeietvawrlflihqfoqjmgvjyejvqktdcdlnlocpyyiwgxyuuujvhvgozhdueajouitorvtnamcuytbpecgbhcdwstpgmqpeyayfmsgcmlkfifqbqstfywrcfrtajygjuenmjdsroodrdoqptwwxgpnjcvoctrxnhchdxywvgjxlqnhgolayqw")<<endl;

  return 0;
}
