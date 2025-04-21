import { pickLan, appendScript } from '../../common/util/pickLan';
import '../../common/css/theme.css';

window.SDK = navigator.userAgent.match(/Android/i) ? 'Android' : 'IOS';

// 兼容一下可能出现的混入
window.__uri = function (link) {
    return link
}

function getQueryString(name) {
    var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)", "i"),
        r = location.search.substr(1).match(reg);
    if (r != null) {
        return decodeURIComponent(r[2]);
    }
    return '';
}

// 先创建一个对象，避免出错 todo  尽量删除
window.lanRes = {};
var lanResName = getQueryString('lan'),//pickLan(getQueryString('lan'), getQueryString, true),
    path = pickLan(lanResName, getQueryString),
    cons;

cons = getQueryString('noConsole');
if (cons && cons == '0' && window.VConsole) {
    window.vConsole = new VConsole();
}
window._evp_sgp = "../plugin";
appendScript("../plugin/chatEntrance.js");
appendScript('../../res/emoji/emoji_' + ((path == 'zhcn' || path == 'zhtw') ? 'zh' : 'en') + '.json');

export default window.lanResName;