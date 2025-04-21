'use strict'

function ServiceGuide(props) {
  var _this3 = this

  var type = props.type,
    config = props.config,
    callback = props.callback,
    onChange = props.onChange,
    isMobile = props.isMobile,
    newSDK = props.newSDK,
    container = props.container,
    backText = props.backText || '返回'

  /**
   * 初始化
   * @param {string} type 初始化组件类型. 1:大窗口 | 2:小浮窗 | 3:h5或sdk
   * @param {Object} config 初始化组件配置数据.
   * @param {function} callback 初始化组件选择入口后的回调.
   * @param {function} onChange 初始化组件组件状态修改事件. ture | false
   */

  this.id = new Date().getTime()
  this.type = type || '2'
  this.config = config || data
  this.callback = callback || function() {}
  this.onChange = onChange || function() {}
  this.open = false // 组件状态
  this.position = ['', ''] // 组件定位
  this.positionNum = [0, 0] // 组件定位
  this.list = []
  this.level = 1
  this.tip = ''
  /** 实例方法 */
  this.init = init
  this.show = show
  this.hide = hide
  this.getStatus = getStatus

  function getByCls(clsName) {
    return document.getElementsByClassName(clsName)
  }
  function createElem(tag) {
    return document.createElement(tag)
  }
  /** 初始化 创建元素 */
  function init() {
    var _this2 = this

    // console.log('start init')
    // 1、生成css文件
    var link = createElem('link')
    link.rel = 'stylesheet'
    link.type = 'text/css'
    // 设置CSS文件的路径
    link.href = _evp_sgp + '/chatEntrance.css'
    // link.href = (newSDK ? '..' : '/visitor') + '/plugin/chatEntrance.css'
    document.head.appendChild(link)

    var guide = getByCls('rr_guide_' + this.id)[0]
    if (guide) {
      guide.remove()
    }

    var body = container || document.getElementsByTagName('body')[0]

    // 1、生成入口菜单样式
    var guideMenuBox = createElem('div')
    guideMenuBox.classList.add('rr_guide_menu_box')
    guideMenuBox.classList.add('rr_guide_' + this.id)
    guideMenuBox.classList.add('rr_guide_menu_box_close')
    guideMenuBox.classList.remove('rr_guide_menu_box_open')
    guideMenuBox.style.visibility = 'hidden'

    // 生成非SDK移动端关闭按钮
    var h5Title = createElem('div')
    var h5TitleBack = createElem('img')
    h5Title.classList.add('rr_guide_h5_title')

    h5TitleBack.width = 22
    h5TitleBack.height = 22
    h5TitleBack.src = _evp_sgp + '/images/backClose.svg'
    h5Title.appendChild(h5TitleBack)
    if (this.type == 1) {
      // 大窗口 居中
      guideMenuBox.classList.remove('rr_guide_menu_box_h5sdk')
      guideMenuBox.classList.add('rr_guide_menu_box_big')
      var rr_guide_menu_box_big_bg = getByCls('rr_guide_menu_box_big_bg')[0]
      var newBigBg = createElem('div')
      if (rr_guide_menu_box_big_bg) {
        rr_guide_menu_box_big_bg.remove()
      }
      newBigBg.classList.add('rr_guide_menu_box_big_bg')
      newBigBg.addEventListener('click', function() {
        _this2.hide()
        newBigBg.classList.remove('rr_guide_menu_box_big_bg_show')
      })
      body.appendChild(newBigBg)
    } else if (this.type == 3) {
      // h5 和 sdk 全屏
      guideMenuBox.classList.remove('rr_guide_menu_box_big')
      guideMenuBox.classList.add('rr_guide_menu_box_h5sdk')
    }  
    
   

    guideMenuBox.style.width = 'auto'
    guideMenuBox.style.maxWidth =
      'calc(100% - ' +
      this.config.routeEntranceMulti.routeEntranceIcon.positionLevel +
      ' px)'

    // guideMenuBox.style.width =
    //   this.config.routeEntranceMulti.routeEntranceIcon.windowWidth + 'px'
    // guideMenuBox.style.height = `fit-content`
    // guideMenuBox.style.maxHeight = `${this.config.routeEntranceMulti.routeEntranceIcon.windowHeight}px`
    this.position = this.config.routeEntranceMulti.routeEntranceIcon.position.split(
      '-'
    )
    this.positionNum[0] = this.config.routeEntranceMulti.routeEntranceIcon.positionLevel
    this.positionNum[1] = this.config.routeEntranceMulti.routeEntranceIcon.positionVertical

    guideMenuBox.style[this.position[0]] = this.positionNum[0] + 'px'
    guideMenuBox.style[this.position[1]] = this.positionNum[1] * 1 + 70 + 'px'

    // 2、生成入口菜单内容标题
    var guideMenuTitle = createElem('div')
    guideMenuTitle.classList.add('rr_guide_menu_title')
    this.tip = (this.config.routeEntranceMulti.routeEntrancePage || {}).pageTips || "";
    guideMenuTitle.innerHTML = this.tip
    guideMenuBox.appendChild(guideMenuTitle)

    if(this.type == 3 && typeof window.ECHAT != 'undefined'){
      h5Title.addEventListener('click',function(){
         // 调用entryBtn.hide()
         try{
          entryBtn.hide()
         }catch(e){
          console.error(e)
         }
      })
      guideMenuBox.appendChild(h5Title)
      guideMenuTitle.style.position= 'relative'
      guideMenuTitle.style.maxWidth= '100%'
      guideMenuTitle.style.left= '0'
    }


    // 3、生产入口菜单内容列表
    var guideMenuList = createElem('div')
    guideMenuList.classList.add('rr_guide_menu_list')
    this.list = this.config.routeEntranceMulti.routeEntranceConfig.items || []
    guideMenuBox.appendChild(guideMenuList)

    body.appendChild(guideMenuBox)

    // end、渲染菜单列表
    renderMenu(this.list)
    return guideMenuBox
  }

  /** 显示咨询入口菜单 */
  function show() {
    this.open = true
    // // 重置菜单数据
    _this3.level = 1
    renderMenu(this.list)
    this.onChange(this.open)
    var rr_guide_menu_box = getByCls('rr_guide_' + this.id)[0]
    if (rr_guide_menu_box) {
      // rr_guide_menu_box.style.height = 'fit-content'
      // rr_guide_menu_box.style.opacity = 1
      // rr_guide_menu_box.style.visibility = 'visible'
      // rr_guide_menu_box.style.padding = '40px 24px'
      // rr_guide_menu_box.style.maxHeight = 'fit-content'
      rr_guide_menu_box.classList.remove('rr_guide_menu_box_close')
      rr_guide_menu_box.classList.add('rr_guide_menu_box_open')
    }

    var rr_guide_menu_box_big_bg = getByCls('rr_guide_menu_box_big_bg')[0]
    if (rr_guide_menu_box_big_bg) {
      rr_guide_menu_box_big_bg.classList.add('rr_guide_menu_box_big_bg_show')
    }
  }

  /** 隐藏咨询入口菜单 */
  function hide() {
    this.open = false
    this.onChange(this.open)
    var rr_guide_menu_box = getByCls('rr_guide_' + this.id)[0]
    if (rr_guide_menu_box) {
      // rr_guide_menu_box.style.height = '0'
      // rr_guide_menu_box.style.opacity = 0
      // rr_guide_menu_box.style.visibility = 'hidden'
      // rr_guide_menu_box.style.maxHeight = '0'
      // rr_guide_menu_box.style.padding = '0 24px'
      rr_guide_menu_box.classList.remove('rr_guide_menu_box_open')
      rr_guide_menu_box.classList.add('rr_guide_menu_box_close')
    }
  }

  /** 获取组件状态开启/关闭 */
  function getStatus() {
    return this.open
  }

  var renderMenu = function renderMenu(list) {
    var menus = getByCls('rr_guide_menu_list')[0]
    var rr_guide_menu_box = getByCls('rr_guide_menu_box')[0]
    var rr_h5_back_btn = getByCls('rr_h5_back_btn')[0]
    if (rr_h5_back_btn) {
      rr_h5_back_btn.remove()
    }

    menus.innerHTML = ''

    if (list && list.length) {
      list.forEach(function(item) {
        var newMenuBox = createElem('div')
        var newMenu = createElem('div')
        var newItemTitleBox = createElem('div')
        var newItemTitle = createElem('div')
        var newItemImgBox = createElem('div')
        var newItemBg = createElem('div')
        var newItemImg = createElem('img')
        var newItemIcon = createElem('img')

        newMenuBox.style.display = 'flex'
        newMenuBox.style.flexDirection = 'column'

        newMenu.classList.add('rr_guide_menu_item')

        newItemTitleBox.classList.add('rr_guide_menu_item_title')
        newItemTitle.innerHTML = item.name
        newItemTitleBox.appendChild(newItemTitle)

        newItemImgBox.classList.add('rr_guide_menu_item_imgBox')
        newItemImgBox.style.background = item.iconColor

        newItemBg.classList.add('rr_guide_menu_bg')
        var opt = _this3.position[0] == 'right' ? '' : '-';
        var bgPosition = 'calc(' + opt + '100% ' + opt + ' 24px)';
        newItemBg.style.transform = 'translateX(' + bgPosition + ')'
        // 控制背景色动画方向

        newItemImg.width = '24'
        newItemImg.src = item.iconUrl || ''

        // newItemIcon.classList.add('rr_guide_menu_item_icon')
        newItemIcon.width = '24'
        newItemIcon.src = _evp_sgp + '/images/right.svg'
        // newItemIcon.src = (newSDK ? '..' : '/visitor') + '/plugin/img/right.svg'
        newItemIcon.style.marginLeft = '12px'

        if(item.iconUrl){
          newItemImgBox.appendChild(newItemImg)
        }
        
        if(type!=3){
          newItemImgBox.appendChild(newItemBg)
        }

        newMenu.appendChild(newItemImgBox)
        newMenu.appendChild(newItemTitleBox)
        if (type == 2 && _this3.position[0] == 'right') {
          newMenu.classList.add('rr_guide_menu_item_right')
        }

        if (item.items) {
          newMenu.appendChild(newItemIcon)
        } else {
          newItemTitleBox.style.maxWidth = `calc(100% - 52px)`
        }

        newMenuBox.addEventListener('click', function() {
          if (item.items) {
            // 渲染二级路由菜单
            _this3.level += 1
            renderMenu(item.items)
          } else {
            // 触发入口进入事件
            entryEvent(item)
          }
        })
        newMenuBox.appendChild(newMenu)
        menus.appendChild(newMenuBox)
      })
    }

    var _this = _this3
    if (_this3.level > 1) {
      // if (_this.type == 3) {
      //   // h5 + sdk移动端
      //   let backBtnBox = createElem('div')
      //   backBtnBox.classList.add('rr_h5_back_btn')

      //   let backBtn = createElem('img')
      //   backBtn.width = 24
      //   backBtn.src = _evp_sgp + '/images/left.svg'

      //   backBtnBox.appendChild(backBtn)
      //   backBtnBox.addEventListener('click', () => {
      //     _this.level = 1
      //     renderMenu(_this.list)
      //   })
      //   rr_guide_menu_box.appendChild(backBtnBox)
      // } else {
      var title = getByCls('rr_guide_menu_title')[0]
      title.innerHTML = ''
      var backIconBox = createElem('div')
      var backTitle = createElem('div')
      backIconBox.classList.add('rr_guide_menu_tip_back')
      backTitle.innerHTML = _this3.tip
      backIconBox.addEventListener('click', function(e) {
        _this.level = 1
        renderMenu(_this.list)
        e.stopPropagation()
      })
      if (isMobile || _this.type == 3) {
        title.classList.add('rr_no_headback')
        backIconBox.classList.add('rr_guide_menu_tip_back_sdk')
        var bText = createElem('span')
        bText.innerHTML = backText
        bText.style.marginLeft = '0'
        backIconBox.appendChild(bText)
        menus.appendChild(backIconBox)
      } else {
        var backIcon = createElem('img')
        backIcon.width = 22
        // backIcon.src = (newSDK ? '..' : '/visitor') + '/plugin/img/left.svg'
        backIcon.src = _evp_sgp + '/images/left.svg'
        backIconBox.appendChild(backIcon)
        title.appendChild(backIconBox)
      }
      if(_this.type == 3 && typeof window.ECHAT != 'undefined'){
        title.style.position= 'relative'
        title.style.left= '0'
      }
      title.appendChild(backTitle)
      // }
    } else {
      var _title = getByCls('rr_guide_menu_title')[0]
      if (isMobile || _this.type == 3) {
        _title.classList.add('rr_no_headback')
      }
      _title.innerHTML = _this3.tip
    }
  }

  var entryEvent = function entryEvent(item) {
    _this3.callback(item)
  }
}
