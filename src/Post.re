open BsReactNative;

let styles = StyleSheet.create(
  Style.{
    "container": style([
      width(Pct(90.0)),
      padding(Pt(20.)),
      backgroundColor(String("#ffffff")),
      borderRadius(10.),
      shadowColor(String("#ff6600")),
      shadowOffset(~height=20. , ~width=20.),
      shadowOpacity(80.)
    ]),
    "textPost": style([
      paddingTop(Pt(10.)),
      paddingBottom(Pt(10.))
    ]),
    "textAttr": style([
      color(String("rgb(175, 29, 188)")),
      fontSize(Float(18.))
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
            <Text style=styles##textAttr> (ReasonReact.string(text)) </Text>
          </View>
          <View style=styles##author>
            <Text>
              (ReasonReact.string("by " ++ author))
            </Text>
          </View>
        </View>
    }
}