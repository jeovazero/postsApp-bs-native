open BsReactNative;

let styles = StyleSheet.create(
  Style.{
    "container": style([
      width(Pct(90.0)),
      padding(Pt(20.)),
      backgroundColor(String("#ffffff")),
      borderColor(String("rgba(175, 29, 188, 0.2)")),
      borderRadius(10.),
      borderBottomWidth(2.),
      shadowRadius(10.),
      shadowColor(String("#000000")),
      shadowOffset(~height=1. , ~width=2.),
      shadowOpacity(0.3),
      elevation(1.)
    ]),
    "textPost": style([
      paddingTop(Pt(10.)),
      paddingBottom(Pt(10.))
    ]),
    "textAttr": style([
      color(String("rgb(175, 29, 188)")),
      fontSize(Float(20.)),
      fontFamily("Amaranth-Regular")
    ]),
    "author": style([
      display(Flex),
      alignItems(FlexEnd)
    ])
  }
)

type post = {
  author: string,
  text: string
};

let component = ReasonReact.statelessComponent("Post");

let make = (~post as {author, text}, ~style, _children) => {
    ...component,
    render: (_self) => {
        <View style=Style.flatten([|styles##container, style|])>
          <View style=styles##textPost>
            <Text style=styles##textAttr> ( ReasonReact.string("\"" ++ text ++ "\"") ) </Text>
          </View>
          <View style=styles##author>
            <Text>
              (ReasonReact.string("by " ++ author))
            </Text>
          </View>
        </View>
    }
}